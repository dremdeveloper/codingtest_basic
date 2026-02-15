#include <algorithm>
#include <iostream>
#include <vector>

int lis_dp_binary_search(const std::vector<int>& arr) {
    std::vector<int> tails;
    for (int x : arr) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

int main() {
    std::vector<int> arr{10,20,10,30,20,50};
    std::cout << lis_dp_binary_search(arr) << '\n';
}
