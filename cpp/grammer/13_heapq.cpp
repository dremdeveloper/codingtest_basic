#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<int> numbers{5,1,4,2};
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    for (int n : numbers) heap.push(n);
    int smallest = heap.top(); heap.pop();
    std::cout << "가장 작은 값 pop: " << smallest << "\n";
}
