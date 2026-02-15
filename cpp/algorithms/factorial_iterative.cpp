/*
- 제목: 팩토리얼(반복)
- 목적: 반복문 기반 누적 곱 패턴을 학습합니다.
- 개념: 2부터 n까지 result에 곱해 n!을 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 핵심 변수 의미: result: 누적 곱, i: 현재 곱할 수
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 120(5!) 출력으로 반복 누적의 결과를 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <stdexcept>

long long factorial_iterative(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

int main() {
    std::cout << factorial_iterative(5) << '\n'; }
