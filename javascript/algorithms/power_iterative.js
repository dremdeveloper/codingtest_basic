/*
- 제목: 거듭제곱 (반복, 이진 지수법)
- 개념: 지수의 비트가 1일 때만 결과에 곱해 빠르게 거듭제곱합니다.
- 시간복잡도(필요한 경우): O(log exp)
- 주요 변수 의미: result: 누적 답, x: 현재 제곱값, n: 처리 중인 지수 비트
- 실행 흐름: n을 오른쪽 쉬프트하며 x를 제곱해가고, n의 최하위 비트가 1이면 result에 곱합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function powerIterative(base, exp) {
  if (exp < 0) throw new Error('exp는 0 이상이어야 합니다.');

  let result = 1;
  let x = base;
  let n = exp;

  while (n > 0) {
    if (n & 1) result *= x;
    x *= x;
    n >>= 1;
  }

  return result;
}

console.log(powerIterative(2, 10));
