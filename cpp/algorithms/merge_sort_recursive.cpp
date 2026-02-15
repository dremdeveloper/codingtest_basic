#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) tmp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    while (i <= m) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = 0; k < (int)tmp.size(); ++k) arr[l + k] = tmp[k];
}

void merge_sort_recursive(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort_recursive(arr, l, m);
    merge_sort_recursive(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    merge_sort_recursive(arr, 0, arr.size()-1);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
