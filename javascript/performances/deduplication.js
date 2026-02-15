function randomInt(max) { return Math.floor(Math.random() * max) + 1; }

function dedupNaive(nums) {
  const result = [];
  for (const x of nums) if (!result.includes(x)) result.push(x);
  return result;
}

function dedupWithSet(nums) {
  const result = [];
  const seen = new Set();
  for (const x of nums) {
    if (!seen.has(x)) {
      seen.add(x);
      result.push(x);
    }
  }
  return result;
}

const n = 600000;
const nums = Array.from({ length: n }, () => randomInt(30000));

let s = process.hrtime.bigint();
const a = dedupNaive(nums);
let t1 = Number(process.hrtime.bigint() - s) / 1e9;

s = process.hrtime.bigint();
const b = dedupWithSet(nums);
let t2 = Number(process.hrtime.bigint() - s) / 1e9;

console.log(`naive 고유개수=${a.length}, 시간=${t1.toFixed(4)}s`);
console.log(`set   고유개수=${b.length}, 시간=${t2.toFixed(4)}s`);
