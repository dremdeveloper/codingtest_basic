#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::pair<std::string, int>> students{{"kim",70},{"lee",90},{"park",80}};

    auto by_score = students;
    std::sort(by_score.begin(), by_score.end(), [](auto& a, auto& b){ return a.second < b.second; });

    auto by_name_desc = students;
    std::sort(by_name_desc.begin(), by_name_desc.end(), [](auto& a, auto& b){ return a.first > b.first; });

    std::cout << "점수순: ";
    for (auto& [n,s] : by_score) std::cout << '(' << n << ',' << s << ") ";
    std::cout << "\n이름 내림차순: ";
    for (auto& [n,s] : by_name_desc) std::cout << '(' << n << ',' << s << ") ";
    std::cout << '\n';
}
