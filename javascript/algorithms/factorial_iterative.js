/*
- 제목: 팩토리얼 (반복)
- 개념: 1부터 n까지 누적 곱으로 팩토리얼을 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: n: 입력 정수, result: 누적 곱 결과, i: 곱셈 반복 인덱스
- 실행 흐름: for 루프로 2~n을 순회하며 result에 차례대로 곱합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function factorialIterative(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');

  let result = 1;
  for (let i = 2; i <= n; i += 1) result *= i;
  return result;
}

console.log(factorialIterative(5));
