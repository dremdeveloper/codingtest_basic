/*
- 제목: 멤버십 조회 성능 비교
- 개념: 같은 조회 문제를 Array.includes와 Set.has로 비교합니다.
- 시간복잡도(필요한 경우): includes O(N), Set.has 평균 O(1)
- 주요 변수 의미: n/q: 데이터/질의 개수, data: 기준 집합, queries: 조회 목록, c1/c2: 일치 개수, t1/t2: 실행 시간
- 실행 흐름: 동일 queries로 list 방식과 set 방식을 각각 실행해 시간과 결과 개수를 비교합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

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
