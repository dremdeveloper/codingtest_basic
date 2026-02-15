function randomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function rangeSumNaive(arr, queries) {
  return queries.map(([l, r]) => {
    let total = 0;
    for (let i = l; i <= r; i += 1) total += arr[i];
    return total;
  });
}

function buildPrefix(arr) {
  const prefix = [0];
  for (const x of arr) prefix.push(prefix[prefix.length - 1] + x);
  return prefix;
}

function rangeSumPrefix(prefix, queries) {
  return queries.map(([l, r]) => prefix[r + 1] - prefix[l]);
}

const n = 400000;
const k = 200000;
const arr = Array.from({ length: n }, () => randomInt(1, 100));
const queries = [];
for (let i = 0; i < k; i += 1) {
  const a = randomInt(0, n - 1);
  const b = randomInt(a, n - 1);
  queries.push([a, b]);
}

let s = process.hrtime.bigint();
const naive = rangeSumNaive(arr, queries);
let t1 = Number(process.hrtime.bigint() - s) / 1e9;

s = process.hrtime.bigint();
const prefix = buildPrefix(arr);
const fast = rangeSumPrefix(prefix, queries);
let t2 = Number(process.hrtime.bigint() - s) / 1e9;

console.log(`naive 첫 결과=${naive[0]}, 시간=${t1.toFixed(4)}s`);
console.log(`prefix 첫 결과=${fast[0]}, 시간=${t2.toFixed(4)}s`);
