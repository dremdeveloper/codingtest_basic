/*
- 제목: 경계 이진 탐색
- 개념: lower/upper bound 구현
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: left/right/mid: 탐색 경계, target: 기준 값
- 실행 흐름: bisectLeft/Right로 시작/끝 경계를 각각 계산합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function bisectLeft(arr, target) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < target) left = mid + 1;
    else right = mid;
  }
  return left;
}

function bisectRight(arr, target) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] <= target) left = mid + 1;
    else right = mid;
  }
  return left;
}

const arr = [1, 2, 2, 2, 5];
const target = 2;
const left = bisectLeft(arr, target);
const right = bisectRight(arr, target);

console.log('배열:', arr);
console.log('target의 왼쪽 경계:', left);
console.log('target 개수:', right - left);
