/*
- 제목: DFS (반복, 스택)
- 개념: 재귀 대신 스택으로 깊이 우선 탐색을 구현합니다.
- 시간복잡도(필요한 경우): O(V + E)
- 주요 변수 의미: stack: 다음 방문 후보(LIFO), visited: 방문 집합, order: 방문 순서
- 실행 흐름: 스택에서 꺼낸 정점을 방문하고, 인접 정점을 역순으로 push해 재귀 DFS와 유사한 순서를 만듭니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function dfsIterative(graph, start) {
  const visited = new Set();
  const stack = [start];
  const order = [];

  while (stack.length) {
    const node = stack.pop();
    if (visited.has(node)) continue;

    visited.add(node);
    order.push(node);

    for (const next of [...graph[node]].reverse()) {
      if (!visited.has(next)) stack.push(next);
    }
  }

  return order;
}

const graphData = { 1: [2, 3], 2: [4, 5], 3: [6], 4: [], 5: [6], 6: [] };
console.log(dfsIterative(graphData, 1));
