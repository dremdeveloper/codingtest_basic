#include <iostream>
#include <vector>

int binary_search_iterative(const std::vector<int>& arr, int target) {
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> numbers{1,3,5,7,9,11,13};
    std::cout << "index: " << binary_search_iterative(numbers, 7) << "\n";
}
