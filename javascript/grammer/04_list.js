/*
- 제목: 배열 기본 조작
- 개념: 추가/삭제/정렬의 기본 동작
- 시간복잡도(필요한 경우): 정렬 O(N log N)
- 주요 변수 의미: arr: 작업 배열
- 실행 흐름: push/splice/sort 적용 전후를 비교합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const arr = [3, 1, 2];
console.log('초기 배열:', arr);

arr.push(4);
arr.splice(arr.indexOf(1), 1);
arr.sort((x, y) => x - y);

console.log('변경 후 배열:', arr);
console.log('첫 번째 원소:', arr[0], '마지막 원소:', arr[arr.length - 1]);
