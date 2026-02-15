"""0/1 배낭 문제 (동적 계획법) 예시."""


def knapsack_01(weights: list[int], values: list[int], capacity: int) -> int:
    n = len(weights)

    # dp[i][c]: i번째 물건까지 고려했을 때, 가방 용량 c로 얻을 수 있는 최대 가치
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        w = weights[i - 1]
        v = values[i - 1]

        for cap in range(capacity + 1):
            # 물건 i를 선택하지 않는 경우
            dp[i][cap] = dp[i - 1][cap]

            # 물건 i를 선택할 수 있다면, 선택/비선택 중 최대값 채택
            if cap >= w:
                dp[i][cap] = max(dp[i][cap], dp[i - 1][cap - w] + v)

    return dp[n][capacity]


if __name__ == "__main__":
    w = [2, 3, 4, 5]
    v = [3, 4, 5, 8]
    print(knapsack_01(w, v, 8))  # 12
