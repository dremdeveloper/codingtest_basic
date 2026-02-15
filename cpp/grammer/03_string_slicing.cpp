#include <iostream>
#include <string>

int main() {
    std::string word = "algorithm";
    std::cout << "원본: " << word << "\n";
    std::cout << "word[1:5] -> " << word.substr(1, 4) << "\n";
    std::cout << "word[:4] -> " << word.substr(0, 4) << "\n";

    std::string step;
    for (size_t i = 0; i < word.size(); i += 2) step += word[i];
    std::cout << "word[::2] -> " << step << "\n";

    std::string rev(word.rbegin(), word.rend());
    std::cout << "word[::-1] -> " << rev << "\n";
}
