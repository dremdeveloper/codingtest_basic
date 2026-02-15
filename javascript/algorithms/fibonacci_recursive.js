/*
- 제목: 피보나치 (재귀)
- 개념: F(n)=F(n-1)+F(n-2) 점화식을 직접 재귀로 구현합니다.
- 시간복잡도(필요한 경우): O(2^N)
- 주요 변수 의미: n: n번째 피보나치 인덱스
- 실행 흐름: n<=1이면 즉시 반환, 아니면 두 하위 문제를 재귀 호출해 합칩니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function fibonacciRecursive(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');
  if (n <= 1) return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

console.log(fibonacciRecursive(10));
