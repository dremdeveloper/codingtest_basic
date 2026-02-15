#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr{1,2,2,2,5};
    int target = 2;

    auto left = std::lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    auto right = std::upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    std::cout << "target의 왼쪽 경계: " << left << "\n";
    std::cout << "target 개수: " << (right - left) << "\n";
}
