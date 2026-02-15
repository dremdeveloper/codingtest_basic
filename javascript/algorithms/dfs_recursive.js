/*
- 제목: DFS (재귀)
- 개념: 한 경로를 끝까지 탐색한 뒤 되돌아오는 깊이 우선 탐색입니다.
- 시간복잡도(필요한 경우): O(V + E)
- 주요 변수 의미: graph: 인접 리스트, start: 현재 정점, visited: 방문 집합, order: 방문 순서
- 실행 흐름: 현재 정점을 방문 처리 후, 아직 방문하지 않은 인접 정점으로 재귀 진입합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function dfsRecursive(graph, start, visited = new Set()) {
  visited.add(start);
  const order = [start];

  for (const next of graph[start]) {
    if (!visited.has(next)) {
      order.push(...dfsRecursive(graph, next, visited));
    }
  }

  return order;
}

const graphData = { 1: [2, 3], 2: [4, 5], 3: [6], 4: [], 5: [6], 6: [] };
console.log(dfsRecursive(graphData, 1));
