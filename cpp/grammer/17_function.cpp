#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int x = 12, y = 18;
    std::cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y) << "\n";
}
