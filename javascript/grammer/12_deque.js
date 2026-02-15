/*
- 제목: 덱 유사 동작
- 개념: 양끝 삽입/삭제 개념
- 시간복잡도(필요한 경우): 앞 연산 O(N), 뒤 연산 O(1)
- 주요 변수 의미: q: 덱처럼 쓰는 배열
- 실행 흐름: unshift/push/shift/pop 순서로 양끝 연산을 보여줍니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const q = [2, 3];
q.push(4);
q.unshift(1);

console.log('추가 후:', q);
const left = q.shift();
const right = q.pop();
console.log('왼쪽에서 꺼낸 값:', left);
console.log('오른쪽에서 꺼낸 값:', right);
console.log('최종 덱 유사 배열:', q);
