#include <iostream>

int main() {
    int total = 0;
    for (int i = 1; i <= 5; ++i) {
        total += i;
        std::cout << "i=" << i << ", 현재 누적합=" << total << "\n";
    }
    std::cout << "최종 합계: " << total << "\n";
}
