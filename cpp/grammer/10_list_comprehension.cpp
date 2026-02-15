#include <iostream>
#include <vector>

int main() {
    std::vector<int> even_squares;
    for (int x = 1; x <= 10; ++x) {
        if (x % 2 == 0) even_squares.push_back(x * x);
    }

    std::cout << "짝수 제곱 리스트: ";
    for (int x : even_squares) std::cout << x << ' ';
    std::cout << "\n원소 개수: " << even_squares.size() << "\n";
}
