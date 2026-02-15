#include <iostream>

long long power_recursive(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    long long half = power_recursive(a, n / 2);
    if (n % 2 == 0) return half * half;
    return half * half * a;
}

int main() { std::cout << power_recursive(2, 10) << '\n'; }
