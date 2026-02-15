#include <iostream>
#include <vector>

int binary_search_recursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binary_search_recursive(arr, target, mid + 1, right);
    return binary_search_recursive(arr, target, left, mid - 1);
}

int main() {
    std::vector<int> numbers{1,3,5,7,9,11,13};
    std::cout << "index: " << binary_search_recursive(numbers, 9, 0, numbers.size()-1) << "\n";
}
