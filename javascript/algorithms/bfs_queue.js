/*
- 제목: BFS (큐)
- 개념: 시작 정점에서 가까운 레벨부터 탐색하는 너비 우선 탐색입니다.
- 시간복잡도(필요한 경우): O(V + E)
- 주요 변수 의미: queue: 방문 대기 정점(FIFO), head: 큐의 pop 인덱스, visited: 방문 집합, order: 방문 순서
- 실행 흐름: queue에서 순서대로 꺼내며 인접 정점을 enqueue합니다. 처음 방문한 순간 visited에 기록합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function bfs(graph, start) {
  const visited = new Set([start]);
  const queue = [start];
  let head = 0;
  const order = [];

  while (head < queue.length) {
    const node = queue[head++];
    order.push(node);

    for (const next of graph[node]) {
      if (!visited.has(next)) {
        visited.add(next);
        queue.push(next);
      }
    }
  }

  return order;
}

const graphData = { 1: [2, 3], 2: [4, 5], 3: [6], 4: [], 5: [6], 6: [] };
console.log(bfs(graphData, 1));
