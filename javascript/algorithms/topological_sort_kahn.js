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
