/*
- 제목: 정렬 기준 지정
- 개념: 비교 함수를 통한 기준 정렬
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: students: [이름,점수] 배열
- 실행 흐름: 점수 오름차순/이름 내림차순 정렬 결과를 비교합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const students = [['kim', 70], ['lee', 90], ['park', 80]];

const byScore = [...students].sort((a, b) => a[1] - b[1]);
const byNameDesc = [...students].sort((a, b) => (a[0] < b[0] ? 1 : -1));

console.log('원본:', students);
console.log('점수순:', byScore);
console.log('이름 내림차순:', byNameDesc);
