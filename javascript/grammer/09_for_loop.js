/*
- 제목: for 반복문
- 개념: 누적합 계산 패턴
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: i: 반복 인덱스, total: 누적합
- 실행 흐름: 반복마다 total 갱신값을 출력해 흐름을 추적합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

let total = 0;
for (let i = 1; i <= 5; i += 1) {
  total += i;
  console.log(`i=${i}, 현재 누적합=${total}`);
}
console.log('최종 합계:', total);
