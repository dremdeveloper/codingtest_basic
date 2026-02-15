/*
- 제목: 중복 제거 성능 비교
- 개념: 배열 includes 검사와 Set 보조 방식의 차이를 확인합니다.
- 시간복잡도(필요한 경우): 배열 검사 O(N^2), Set 평균 O(N)
- 주요 변수 의미: nums: 입력 배열, result: 중복 제거 결과, seen: 이미 본 값 집합, t1/t2: 실행 시간
- 실행 흐름: 같은 nums에 대해 두 방식으로 중복 제거를 수행하고 길이와 시간을 비교합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

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
