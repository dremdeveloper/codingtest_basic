/*
- 제목: 팩토리얼(재귀)
- 목적: 기저 사례(base case)와 재귀 전개를 학습합니다.
- 개념: n! = n*(n-1)!를 그대로 코드로 옮겼습니다.
- 시간복잡도(필요한 경우): O(N)
- 핵심 변수 의미: n: 곱해 나갈 마지막 정수
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 120(5!) 출력으로 재귀 곱셈 누적 결과를 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <stdexcept>

long long factorial_recursive(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

int main() {
    std::cout << factorial_recursive(5) << '\n'; }
