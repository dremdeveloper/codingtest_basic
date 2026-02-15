/*
- 제목: 최대공약수 GCD (반복)
- 개념: 유클리드 호제법을 while 반복으로 구현합니다.
- 시간복잡도(필요한 경우): O(log min(a,b))
- 주요 변수 의미: a/b: 현재 단계의 두 수(반복마다 갱신)
- 실행 흐름: (a,b) <- (b,a%b) 갱신을 b==0까지 반복합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function gcdIterative(a, b) {
  a = Math.abs(a);
  b = Math.abs(b);

  while (b !== 0) {
    [a, b] = [b, a % b];
  }
  return a;
}

console.log(gcdIterative(48, 18));
