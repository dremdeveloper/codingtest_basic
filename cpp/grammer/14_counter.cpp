#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string text = "banana";
    std::unordered_map<char,int> counter;
    for (char c : text) counter[c]++;

    std::cout << "문자열: " << text << "\n";
    for (auto& [c, n] : counter) std::cout << c << ':' << n << ' ';
    std::cout << '\n';
}
