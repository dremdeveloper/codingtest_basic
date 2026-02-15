#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

int contains_with_list(const std::vector<int>& data, const std::vector<int>& queries) {
    int count = 0;
    for (int q : queries) {
        if (std::find(data.begin(), data.end(), q) != data.end()) count++;
    }
    return count;
}

int contains_with_set(const std::vector<int>& data, const std::vector<int>& queries) {
    std::unordered_set<int> s(data.begin(), data.end());
    int count = 0;
    for (int q : queries) if (s.count(q)) count++;
    return count;
}

int main() {
    int n = 400000, qn = 200000;
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) data[i] = i;

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, n * 2);
    std::vector<int> queries(qn);
    for (int& x : queries) x = dist(rng);

    auto s1 = std::chrono::steady_clock::now();
    int c1 = contains_with_list(data, queries);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    int c2 = contains_with_set(data, queries);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "list 결과=" << c1 << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "set  결과=" << c2 << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
