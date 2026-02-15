function makeSets(size) {
  const parent = Array.from({ length: size }, (_, i) => i);
  const rank = Array(size).fill(0);
  return [parent, rank];
}

function find(parent, x) {
  if (parent[x] !== x) parent[x] = find(parent, parent[x]);
  return parent[x];
}

function union(parent, rank, a, b) {
  const rootA = find(parent, a);
  const rootB = find(parent, b);

  if (rootA === rootB) return false;

  if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
  else if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
  else {
    parent[rootB] = rootA;
    rank[rootA] += 1;
  }

  return true;
}

const [parentData, rankData] = makeSets(7);
union(parentData, rankData, 1, 2);
union(parentData, rankData, 2, 3);
union(parentData, rankData, 4, 5);
console.log(find(parentData, 1) === find(parentData, 3));
console.log(find(parentData, 1) === find(parentData, 5));
