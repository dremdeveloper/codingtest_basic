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
