/*
- 제목: 위상 정렬 (Kahn)
- 개념: 진입차수 0 정점부터 처리해 DAG의 선후관계를 선형 순서로 만듭니다.
- 시간복잡도(필요한 경우): O(V + E)
- 주요 변수 의미: indegree: 각 정점의 진입차수, queue: 현재 진입차수 0 정점, order: 결과 순서
- 실행 흐름: queue에서 꺼낸 정점의 간선을 제거하며(차수 감소) 새롭게 0이 된 정점을 enqueue합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function topologicalSortKahn(graph) {
  const indegree = {};
  for (const node of Object.keys(graph)) indegree[node] = 0;

  for (const node of Object.keys(graph)) {
    for (const next of graph[node]) indegree[next] += 1;
  }

  const queue = Object.keys(graph).filter((node) => indegree[node] === 0);
  let head = 0;
  const order = [];

  while (head < queue.length) {
    const node = queue[head++];
    order.push(Number(node));

    for (const next of graph[node]) {
      indegree[next] -= 1;
      if (indegree[next] === 0) queue.push(String(next));
    }
  }

  if (order.length !== Object.keys(graph).length) {
    throw new Error('사이클이 존재하여 위상 정렬이 불가능합니다.');
  }

  return order;
}

const dag = { 1: [2, 3], 2: [4], 3: [4, 5], 4: [6], 5: [6], 6: [] };
console.log(topologicalSortKahn(dag));
