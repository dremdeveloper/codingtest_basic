#include <deque>
#include <iostream>

int main() {
    std::deque<int> q{2,3};
    q.push_back(4);
    q.push_front(1);

    int left = q.front(); q.pop_front();
    int right = q.back(); q.pop_back();

    std::cout << "왼쪽에서 꺼낸 값: " << left << "\n";
    std::cout << "오른쪽에서 꺼낸 값: " << right << "\n";
}
