#include <chrono>
#include <iostream>
#include <string>
#include <vector>

std::string build_with_plus(const std::vector<std::string>& chunks) {
    std::string result;
    for (const auto& ch : chunks) result += ch;
    return result;
}

std::string build_with_reserve(const std::vector<std::string>& chunks) {
    size_t total = 0;
    for (const auto& ch : chunks) total += ch.size();
    std::string result;
    result.reserve(total);
    for (const auto& ch : chunks) result += ch;
    return result;
}

int main() {
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<std::string> chunks;
    chunks.reserve(letters.size() * 80000);
    for (int i = 0; i < 80000; ++i) for (char c : letters) chunks.emplace_back(1, c);

    auto s1 = std::chrono::steady_clock::now();
    auto a = build_with_plus(chunks);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto b = build_with_reserve(chunks);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "+= 길이=" << a.size() << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "reserve 길이=" << b.size() << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
