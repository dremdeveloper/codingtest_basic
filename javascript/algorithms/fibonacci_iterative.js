/*
- 제목: 피보나치 (반복)
- 개념: 이전 두 항만 유지해 선형 시간에 피보나치를 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: a/b: 직전 두 피보나치 값(F(k-1), F(k)), n: 목표 인덱스
- 실행 흐름: 반복마다 [a,b]=[b,a+b]로 상태를 한 칸 전진시킵니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function fibonacciIterative(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');
  if (n <= 1) return n;

  let a = 0;
  let b = 1;
  for (let i = 2; i <= n; i += 1) {
    [a, b] = [b, a + b];
  }
  return b;
}

console.log(fibonacciIterative(10));
