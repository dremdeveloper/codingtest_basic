/*
- 제목: 문자열 결합 성능 비교
- 개념: 반복 += 와 join의 실행 시간을 비교합니다.
- 시간복잡도(필요한 경우): += 최악 O(N^2), join O(N)
- 주요 변수 의미: chunks: 결합할 문자열 조각, a/b: 결합 결과, t1/t2: 각 방식 실행 시간
- 실행 흐름: 같은 chunks를 대상으로 += 루프와 join을 각각 실행해 처리 시간을 측정합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

const letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
const chunks = Array.from({ length: letters.length * 80000 }, (_, i) => letters[i % letters.length]);

function buildWithPlus(parts) {
  let result = '';
  for (const ch of parts) result += ch;
  return result;
}

function buildWithJoin(parts) {
  return parts.join('');
}

let s = process.hrtime.bigint();
const a = buildWithPlus(chunks);
let t1 = Number(process.hrtime.bigint() - s) / 1e9;

s = process.hrtime.bigint();
const b = buildWithJoin(chunks);
let t2 = Number(process.hrtime.bigint() - s) / 1e9;

console.log(`+= 길이=${a.length}, 시간=${t1.toFixed(4)}s`);
console.log(`join 길이=${b.length}, 시간=${t2.toFixed(4)}s`);
