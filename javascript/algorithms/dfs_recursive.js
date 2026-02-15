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
