/*
- 제목: 산술 연산자
- 개념: 사칙연산/나머지/거듭제곱 확인
- 시간복잡도(필요한 경우): O(1)
- 주요 변수 의미: a,b: 피연산자
- 실행 흐름: 각 연산자의 계산 결과를 한 줄씩 확인합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const a = 7;
const b = 3;

console.log(`${a} + ${b} =`, a + b);
console.log(`${a} - ${b} =`, a - b);
console.log(`${a} * ${b} =`, a * b);
console.log(`${Math.floor(a / b)} (몫)`);
console.log(`${a} % ${b} =`, a % b);
console.log('2 ** 5 =', 2 ** 5);
