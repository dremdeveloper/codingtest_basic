function randomInt(max) { return Math.floor(Math.random() * (max + 1)); }

function containsWithList(data, queries) {
  let count = 0;
  for (const q of queries) if (data.includes(q)) count += 1;
  return count;
}

function containsWithSet(data, queries) {
  const dataSet = new Set(data);
  let count = 0;
  for (const q of queries) if (dataSet.has(q)) count += 1;
  return count;
}

const n = 400000;
const q = 200000;
const data = Array.from({ length: n }, (_, i) => i);
const queries = Array.from({ length: q }, () => randomInt(n * 2));

let s = process.hrtime.bigint();
const c1 = containsWithList(data, queries);
let t1 = Number(process.hrtime.bigint() - s) / 1e9;

s = process.hrtime.bigint();
const c2 = containsWithSet(data, queries);
let t2 = Number(process.hrtime.bigint() - s) / 1e9;

console.log(`list 결과=${c1}, 시간=${t1.toFixed(4)}s`);
console.log(`set  결과=${c2}, 시간=${t2.toFixed(4)}s`);
