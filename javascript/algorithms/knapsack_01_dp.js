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
