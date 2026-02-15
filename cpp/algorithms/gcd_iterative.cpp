#include <iostream>

int gcd_iterative(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() { std::cout << gcd_iterative(48, 18) << '\n'; }
