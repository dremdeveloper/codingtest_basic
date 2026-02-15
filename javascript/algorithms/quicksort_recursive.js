/*
- 제목: 퀵 정렬 (재귀)
- 개념: pivot 기준으로 작은 값/같은 값/큰 값으로 분할해 재귀 정렬합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 주요 변수 의미: pivot: 분할 기준값, left/middle/right: 분할된 부분배열
- 실행 흐름: left와 right를 재귀 정렬 후 middle과 이어붙여 결과를 만듭니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function quicksortRecursive(arr) {
  if (arr.length <= 1) return arr;

  const pivot = arr[Math.floor(arr.length / 2)];
  const left = arr.filter((x) => x < pivot);
  const middle = arr.filter((x) => x === pivot);
  const right = arr.filter((x) => x > pivot);

  return [...quicksortRecursive(left), ...middle, ...quicksortRecursive(right)];
}

console.log(quicksortRecursive([8, 4, 7, 3, 9, 2, 6, 5]));
