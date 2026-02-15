/*
- 제목: 빠른 입력 팁
- 개념: Node.js 대량 입력 패턴 소개
- 시간복잡도(필요한 경우): 입력 크기에 비례
- 주요 변수 의미: example: 예시 입력 문자열
- 실행 흐름: 실전에서 쓰는 fs.readFileSync(0,"utf8") 패턴을 설명합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const example = '3\n10 20 30\n';
console.log('빠른 입력 기본 형태: Node.js에서는 fs.readFileSync(0, "utf8") 사용');
console.log('예시 입력 문자열:');
console.log(example);
