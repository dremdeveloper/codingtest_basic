/*
- 제목: LIS (이진 탐색)
- 개념: tails[k]를 길이 k+1 부분수열의 최소 끝값으로 유지합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: tails: 길이별 최소 꼬리값 배열, idx: x가 들어갈 위치
- 실행 흐름: 각 원소 x마다 lower bound를 찾아 tails를 교체/확장합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function bisectLeft(arr, x) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

function lisLength(arr) {
  const tails = [];

  for (const x of arr) {
    const idx = bisectLeft(tails, x);
    if (idx === tails.length) tails.push(x);
    else tails[idx] = x;
  }

  return tails.length;
}

console.log(lisLength([10, 20, 10, 30, 20, 50]));
