#include <algorithm>
#include <iostream>
#include <vector>

void merge_sort_iterative(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> tmp(n);
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int l = i;
            int m = std::min(i + width, n);
            int r = std::min(i + 2 * width, n);
            int p = l, q = m, t = l;
            while (p < m && q < r) tmp[t++] = (arr[p] <= arr[q]) ? arr[p++] : arr[q++];
            while (p < m) tmp[t++] = arr[p++];
            while (q < r) tmp[t++] = arr[q++];
            for (int k = l; k < r; ++k) arr[k] = tmp[k];
        }
    }
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    merge_sort_iterative(arr);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
