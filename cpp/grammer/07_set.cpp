#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> nums{1, 1, 2, 3, 3, 4};
    std::unordered_set<int> unique(nums.begin(), nums.end());

    std::cout << "3이 있는가?: " << (unique.count(3) ? "True" : "False") << "\n";
    std::cout << "10이 있는가?: " << (unique.count(10) ? "True" : "False") << "\n";
}
