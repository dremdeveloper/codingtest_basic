/*
- 제목: 객체 딕셔너리
- 개념: 키-값 조회/추가/갱신
- 시간복잡도(필요한 경우): 평균 O(1)
- 주요 변수 의미: score: 점수 객체
- 실행 흐름: 키 추가/수정 후 keys와 값 조회를 확인합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const score = { A: 100, B: 80 };
console.log('초기 객체:', score);

score.C = 95;
score.B = 85;

console.log('A 점수 조회:', score.A);
console.log('모든 키:', Object.keys(score));
console.log('최종 객체:', score);
