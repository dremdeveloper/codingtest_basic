/*
- 제목: 거듭제곱 (재귀, 분할정복)
- 개념: 지수를 절반으로 줄여 필요한 곱셈 수를 감소시킵니다.
- 시간복잡도(필요한 경우): O(log exp)
- 주요 변수 의미: base: 밑, exp: 지수, half: exp/2 결과의 재사용 값
- 실행 흐름: half를 한 번 계산해 짝수/홀수 지수에 맞게 조합합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function powerRecursive(base, exp) {
  if (exp < 0) throw new Error('exp는 0 이상이어야 합니다.');
  if (exp === 0) return 1;
  if (exp === 1) return base;

  const half = powerRecursive(base, Math.floor(exp / 2));
  if (exp % 2 === 0) return half * half;
  return half * half * base;
}

console.log(powerRecursive(2, 10));
