/*
- 제목: 다익스트라 최단 경로 (최소 힙)
- 개념: 음수 가중치가 없는 그래프에서 시작점 기준 최단거리를 구합니다.
- 시간복잡도(필요한 경우): O((V + E) log V)
- 주요 변수 의미: dist: 현재까지의 최단거리 표, pq: (거리, 정점) 최소 힙, curDist: 힙에서 꺼낸 후보 거리, cand: 완화 후보 거리
- 실행 흐름: 가장 짧은 후보를 먼저 꺼내고(relaxation), 더 짧은 경로를 발견하면 dist 갱신 후 힙에 다시 넣습니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

class MinHeap {
  constructor() { this.data = []; }
  push(item) {
    this.data.push(item);
    let i = this.data.length - 1;
    while (i > 0) {
      const p = Math.floor((i - 1) / 2);
      if (this.data[p][0] <= this.data[i][0]) break;
      [this.data[p], this.data[i]] = [this.data[i], this.data[p]];
      i = p;
    }
  }
  pop() {
    if (!this.data.length) return null;
    const top = this.data[0];
    const end = this.data.pop();
    if (this.data.length) {
      this.data[0] = end;
      let i = 0;
      while (true) {
        let s = i;
        const l = i * 2 + 1;
        const r = i * 2 + 2;
        if (l < this.data.length && this.data[l][0] < this.data[s][0]) s = l;
        if (r < this.data.length && this.data[r][0] < this.data[s][0]) s = r;
        if (s === i) break;
        [this.data[i], this.data[s]] = [this.data[s], this.data[i]];
        i = s;
      }
    }
    return top;
  }
  get size() { return this.data.length; }
}

function dijkstra(graph, start) {
  const INF = Number.MAX_SAFE_INTEGER;
  const dist = {};
  for (const node of Object.keys(graph)) dist[node] = INF;
  dist[start] = 0;

  const pq = new MinHeap();
  pq.push([0, start]);

  while (pq.size) {
    const [curDist, node] = pq.pop();
    if (curDist > dist[node]) continue;

    for (const [next, weight] of graph[node]) {
      const cand = curDist + weight;
      if (cand < dist[next]) {
        dist[next] = cand;
        pq.push([cand, next]);
      }
    }
  }

  return dist;
}

const weightedGraph = {
  1: [[2, 2], [3, 5]],
  2: [[3, 1], [4, 2]],
  3: [[4, 3], [5, 1]],
  4: [[5, 2]],
  5: [],
};
console.log(dijkstra(weightedGraph, 1));
