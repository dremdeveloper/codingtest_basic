#include <iostream>
#include <stdexcept>

long long fibonacci_iterative(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long t = a + b;
        a = b;
        b = t;
    }
    return b;
}

int main() { std::cout << fibonacci_iterative(10) << '\n'; }
