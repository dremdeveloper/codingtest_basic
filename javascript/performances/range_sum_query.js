/*
- 제목: 구간 합 질의 성능 비교
- 개념: 매 질의 합산 방식과 누적합(prefix sum) 방식을 비교합니다.
- 시간복잡도(필요한 경우): naive O(K*N), prefix O(N+K)
- 주요 변수 의미: arr: 원본 수열, queries: [l,r] 질의 목록, prefix: 누적합 배열, naive/fast: 결과 배열
- 실행 흐름: naive는 각 질의마다 합을 계산하고, prefix는 전처리 후 O(1)로 질의에 답합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

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
