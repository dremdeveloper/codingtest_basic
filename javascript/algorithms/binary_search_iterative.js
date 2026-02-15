/*
- 제목: 이진 탐색 (반복)
- 개념: 정렬된 배열에서 탐색 구간을 절반씩 줄여 목표값의 위치를 찾습니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: arr: 정렬된 입력 배열, target: 찾을 값, left/right: 현재 탐색 구간 경계, mid: 가운데 인덱스
- 실행 흐름: left~right 범위를 유지하며 mid와 target을 비교해 왼쪽/오른쪽 절반만 남깁니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function binarySearchIterative(arr, target) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] === target) return mid;
    if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
  }

  return -1;
}

const numbers = [1, 3, 5, 7, 9, 11, 13];
console.log(`index: ${binarySearchIterative(numbers, 7)}`);
