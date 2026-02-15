/*
- 제목: 병합 정렬 (재귀)
- 개념: 배열을 분할한 뒤 정렬된 두 부분배열을 병합합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: left/right: 분할된 부분배열, merged: 병합 결과, i/j: 비교 인덱스
- 실행 흐름: 길이 1 이하가 될 때까지 분할하고, 병합 단계에서 정렬 순서를 복원합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function merge(left, right) {
  const merged = [];
  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) merged.push(left[i++]);
    else merged.push(right[j++]);
  }

  return [...merged, ...left.slice(i), ...right.slice(j)];
}

function mergeSortRecursive(arr) {
  if (arr.length <= 1) return arr;
  const mid = Math.floor(arr.length / 2);
  return merge(mergeSortRecursive(arr.slice(0, mid)), mergeSortRecursive(arr.slice(mid)));
}

console.log(mergeSortRecursive([5, 2, 9, 1, 3, 7]));
