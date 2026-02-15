#include <iostream>
#include <stack>
#include <vector>

int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) if (arr[j] <= pivot) std::swap(arr[i++], arr[j]);
    std::swap(arr[i], arr[r]);
    return i;
}

void quicksort_iterative(std::vector<int>& arr) {
    std::stack<std::pair<int,int>> st;
    st.push({0, (int)arr.size()-1});
    while (!st.empty()) {
        auto [l, r] = st.top(); st.pop();
        if (l >= r) continue;
        int p = partition(arr, l, r);
        st.push({l, p - 1});
        st.push({p + 1, r});
    }
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    quicksort_iterative(arr);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
