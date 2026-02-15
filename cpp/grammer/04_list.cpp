#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3, 1, 2};
    std::cout << "초기 리스트: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << "\n";

    arr.push_back(4);
    arr.erase(std::find(arr.begin(), arr.end(), 1));
    std::sort(arr.begin(), arr.end());

    std::cout << "변경 후 리스트: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << "\n";
    std::cout << "첫 번째 원소: " << arr.front() << " 마지막 원소: " << arr.back() << "\n";
}
