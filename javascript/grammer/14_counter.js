/*
- 제목: 빈도수 세기
- 개념: Counter 개념 대응
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: counter: 문자별 빈도 객체, top1: 최빈 항목
- 실행 흐름: 문자열을 순회하며 빈도를 누적합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const text = 'banana';
const counter = {};

for (const ch of text) counter[ch] = (counter[ch] ?? 0) + 1;
const top1 = Object.entries(counter).sort((a, b) => b[1] - a[1])[0];

console.log('문자열:', text);
console.log('빈도수 객체:', counter);
console.log('가장 많이 나온 문자 1개:', top1);
