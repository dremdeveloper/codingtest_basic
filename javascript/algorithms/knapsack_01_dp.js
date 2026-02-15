/*
- 제목: 0/1 배낭 (DP)
- 개념: 각 물건을 담을지 말지 선택하며 최대 가치를 누적합니다.
- 시간복잡도(필요한 경우): O(N*C)
- 주요 변수 의미: weights/values: 물건의 무게/가치, capacity: 배낭 용량, dp[i][cap]: i개 물건 고려 시 최대 가치
- 실행 흐름: 이전 행(dp[i-1]) 기반으로 비선택/선택 값을 비교해 최댓값을 채웁니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function knapsack01(weights, values, capacity) {
  const n = weights.length;
  const dp = Array.from({ length: n + 1 }, () => Array(capacity + 1).fill(0));

  for (let i = 1; i <= n; i += 1) {
    const w = weights[i - 1];
    const v = values[i - 1];

    for (let cap = 0; cap <= capacity; cap += 1) {
      dp[i][cap] = dp[i - 1][cap];
      if (cap >= w) dp[i][cap] = Math.max(dp[i][cap], dp[i - 1][cap - w] + v);
    }
  }

  return dp[n][capacity];
}

console.log(knapsack01([2, 3, 4, 5], [3, 4, 5, 8], 8));
