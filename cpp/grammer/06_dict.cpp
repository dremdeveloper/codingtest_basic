#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> score{{"A", 100}, {"B", 80}};
    score["C"] = 95;
    score["B"] = 85;

    std::cout << "A 점수 조회: " << score["A"] << "\n";
    std::cout << "모든 키: ";
    for (const auto& [k, _] : score) std::cout << k << ' ';
    std::cout << "\n";
}
