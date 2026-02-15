#include <iostream>
#include <vector>

int main() {
    std::vector<char> items{'A','B','C','D'};
    int count = 0;
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t j = i + 1; j < items.size(); ++j) {
            std::cout << '(' << items[i] << ',' << items[j] << ") ";
            ++count;
        }
    }
    std::cout << "\n조합 개수: " << count << "\n";
}
