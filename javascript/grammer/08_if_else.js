/*
- 제목: 조건문
- 개념: if/else if/else 분기
- 시간복잡도(필요한 경우): O(1)
- 주요 변수 의미: score: 입력 점수, grade: 판정 결과
- 실행 흐름: 조건 순서대로 등급을 판정합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const score = 82;
let grade;

if (score >= 90) grade = 'A';
else if (score >= 80) grade = 'B';
else grade = 'C';

console.log('점수:', score);
console.log('등급:', grade);
