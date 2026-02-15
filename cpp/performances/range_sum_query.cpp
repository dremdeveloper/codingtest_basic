#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<long long> range_sum_naive(const std::vector<int>& arr, const std::vector<std::pair<int,int>>& queries) {
    std::vector<long long> result;
    result.reserve(queries.size());
    for (auto [l, r] : queries) {
        long long sum = 0;
        for (int i = l; i <= r; ++i) sum += arr[i];
        result.push_back(sum);
    }
    return result;
}

std::vector<long long> build_prefix(const std::vector<int>& arr) {
    std::vector<long long> prefix(arr.size() + 1, 0);
    for (size_t i = 0; i < arr.size(); ++i) prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}

std::vector<long long> range_sum_prefix(const std::vector<long long>& prefix, const std::vector<std::pair<int,int>>& queries) {
    std::vector<long long> result;
    result.reserve(queries.size());
    for (auto [l, r] : queries) result.push_back(prefix[r + 1] - prefix[l]);
    return result;
}

int main() {
    int n = 200000, k = 100000;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> value_dist(1, 100);

    std::vector<int> arr(n);
    for (int& x : arr) x = value_dist(rng);

    std::vector<std::pair<int,int>> queries;
    queries.reserve(k);
    std::uniform_int_distribution<int> idx_dist(0, n - 1);
    for (int i = 0; i < k; ++i) {
        int a = idx_dist(rng), b = idx_dist(rng);
        if (a > b) std::swap(a, b);
        queries.push_back({a, b});
    }

    auto s1 = std::chrono::steady_clock::now();
    auto naive = range_sum_naive(arr, queries);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto prefix = build_prefix(arr);
    auto fast = range_sum_prefix(prefix, queries);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "naive 첫 결과=" << naive[0] << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "prefix 첫 결과=" << fast[0] << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
