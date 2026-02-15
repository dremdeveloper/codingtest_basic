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
