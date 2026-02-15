#include <iostream>
#include <stdexcept>

long long fibonacci_recursive(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() { std::cout << fibonacci_recursive(10) << '\n'; }
