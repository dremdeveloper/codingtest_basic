#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, int> point{3, 7};
    auto [x, y] = point;
    std::cout << "튜플 원본: (" << x << ", " << y << ")\n";
    std::cout << "언패킹 결과 x, y: " << x << ' ' << y << "\n";
    std::cout << "튜플 길이: " << std::tuple_size<decltype(point)>::value << "\n";
}
