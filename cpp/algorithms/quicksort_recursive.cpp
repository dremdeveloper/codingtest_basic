#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) {
        if (arr[j] <= pivot) std::swap(arr[i++], arr[j]);
    }
    std::swap(arr[i], arr[r]);
    return i;
}

void quicksort_recursive(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quicksort_recursive(arr, l, p - 1);
    quicksort_recursive(arr, p + 1, r);
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    quicksort_recursive(arr, 0, arr.size()-1);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
