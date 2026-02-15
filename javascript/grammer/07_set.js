/*
- 제목: Set 사용법
- 개념: 중복 제거와 포함 검사
- 시간복잡도(필요한 경우): 평균 O(1)
- 주요 변수 의미: nums: 원본 배열, uniqueNums: Set
- 실행 흐름: 배열->Set 변환 후 has로 포함 여부를 확인합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const nums = [1, 1, 2, 3, 3, 4];
const uniqueNums = new Set(nums);

console.log('원본 배열:', nums);
console.log('중복 제거 결과:', [...uniqueNums]);
console.log('3이 있는가?:', uniqueNums.has(3));
console.log('10이 있는가?:', uniqueNums.has(10));
