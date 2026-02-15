/*
- 제목: 병합 정렬 (반복, Bottom-Up)
- 개념: 작은 구간(길이1)부터 시작해 병합 구간을 2배씩 키웁니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: size: 현재 병합 단위 길이, left/mid/right: 병합 구간 경계, result: 작업 배열
- 실행 흐름: 각 단계에서 인접한 두 구간을 mergeSections로 합치고 size를 2배로 증가시킵니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function mergeSections(arr, left, mid, right) {
  const leftPart = arr.slice(left, mid);
  const rightPart = arr.slice(mid, right);
  let i = 0;
  let j = 0;
  let k = left;

  while (i < leftPart.length && j < rightPart.length) {
    if (leftPart[i] <= rightPart[j]) arr[k++] = leftPart[i++];
    else arr[k++] = rightPart[j++];
  }

  while (i < leftPart.length) arr[k++] = leftPart[i++];
  while (j < rightPart.length) arr[k++] = rightPart[j++];
}

function mergeSortIterative(arr) {
  const result = [...arr];
  const n = result.length;
  let size = 1;

  while (size < n) {
    for (let left = 0; left < n; left += size * 2) {
      const mid = Math.min(left + size, n);
      const right = Math.min(left + size * 2, n);
      mergeSections(result, left, mid, right);
    }
    size *= 2;
  }

  return result;
}

console.log(mergeSortIterative([5, 2, 9, 1, 3, 7]));
