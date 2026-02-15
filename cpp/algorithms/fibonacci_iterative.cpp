/*
- 제목: 피보나치(반복)
- 목적: 재귀 대비 효율적인 피보나치 계산법을 익힙니다.
- 개념: 직전 두 항(a,b)을 갱신하며 n번째 값을 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 핵심 변수 의미: a: 이전 항, b: 현재 항, i: 반복 단계
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 55(F(10)) 출력으로 반복 DP 스타일 계산을 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

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

int main() {
    std::cout << fibonacci_iterative(10) << '\n'; }
