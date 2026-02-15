/*
- 제목: 변수와 자료형
- 개념: 기본 타입(number/string/boolean) 확인
- 시간복잡도(필요한 경우): O(1)
- 주요 변수 의미: number/pi/text/flag: 예시 변수
- 실행 흐름: 값과 typeof 출력으로 타입을 확인합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const number = 10;
const pi = 3.14;
const text = 'javascript';
const flag = true;

console.log('number 타입:', typeof number, '값:', number);
console.log('pi 타입:', typeof pi, '값:', pi);
console.log('text 타입:', typeof text, '길이:', text.length);
console.log('flag 타입:', typeof flag, '값:', flag);
