/*
- 제목: filter + map
- 개념: 컴프리헨션 대응 패턴
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: evenSquares: 짝수 제곱 결과
- 실행 흐름: 1~10 생성 -> 짝수 필터 -> 제곱 변환 순서로 처리합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const evenSquares = Array.from({ length: 10 }, (_, i) => i + 1)
  .filter((x) => x % 2 === 0)
  .map((x) => x * x);

console.log('짝수 제곱 배열:', evenSquares);
console.log('원소 개수:', evenSquares.length);
