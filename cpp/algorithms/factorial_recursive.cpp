#include <iostream>
#include <stdexcept>

long long factorial_recursive(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

int main() { std::cout << factorial_recursive(5) << '\n'; }
