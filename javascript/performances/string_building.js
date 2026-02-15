const letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
const chunks = Array.from({ length: letters.length * 80000 }, (_, i) => letters[i % letters.length]);

function buildWithPlus(parts) {
  let result = '';
  for (const ch of parts) result += ch;
  return result;
}

function buildWithJoin(parts) {
  return parts.join('');
}

let s = process.hrtime.bigint();
const a = buildWithPlus(chunks);
let t1 = Number(process.hrtime.bigint() - s) / 1e9;

s = process.hrtime.bigint();
const b = buildWithJoin(chunks);
let t2 = Number(process.hrtime.bigint() - s) / 1e9;

console.log(`+= 길이=${a.length}, 시간=${t1.toFixed(4)}s`);
console.log(`join 길이=${b.length}, 시간=${t2.toFixed(4)}s`);
