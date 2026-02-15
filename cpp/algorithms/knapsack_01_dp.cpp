#include <iostream>
#include <vector>

int knapsack_01_dp(const std::vector<int>& w, const std::vector<int>& v, int cap) {
    std::vector<int> dp(cap + 1, 0);
    for (size_t i = 0; i < w.size(); ++i) {
        for (int c = cap; c >= w[i]; --c) {
            dp[c] = std::max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    return dp[cap];
}

int main() {
    std::vector<int> w{2,1,3,2}, v{12,10,20,15};
    std::cout << knapsack_01_dp(w, v, 5) << '\n';
}
