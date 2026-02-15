#include <chrono>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

std::vector<int> dedup_naive(const std::vector<int>& nums) {
    std::vector<int> result;
    for (int x : nums) {
        bool exists = false;
        for (int y : result) {
            if (y == x) { exists = true; break; }
        }
        if (!exists) result.push_back(x);
    }
    return result;
}

std::vector<int> dedup_with_set(const std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (!seen.count(x)) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    int n = 300000;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 30000);
    std::vector<int> nums(n);
    for (int& x : nums) x = dist(rng);

    auto s1 = std::chrono::steady_clock::now();
    auto a = dedup_naive(nums);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto b = dedup_with_set(nums);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "naive 고유개수=" << a.size() << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "set   고유개수=" << b.size() << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
