/*
- 제목: 이진 탐색 (재귀)
- 개념: 정렬된 배열에서 재귀 호출로 범위를 절반씩 줄이며 값을 찾습니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: arr: 정렬 배열, target: 목표값, left/right: 현재 재귀 탐색 경계, mid: 중간 인덱스
- 실행 흐름: 기저조건(left>right)로 종료하고, mid 비교 결과에 따라 한쪽 구간만 재귀 호출합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function binarySearchRecursive(arr, target, left, right) {
  if (left > right) return -1;

  const mid = Math.floor((left + right) / 2);
  if (arr[mid] === target) return mid;
  if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, right);
  return binarySearchRecursive(arr, target, left, mid - 1);
}

const numbers = [1, 3, 5, 7, 9, 11, 13];
console.log(`index: ${binarySearchRecursive(numbers, 9, 0, numbers.length - 1)}`);
