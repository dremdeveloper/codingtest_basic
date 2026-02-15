/*
- 제목: 거듭제곱(재귀, 분할정복)
- 목적: 지수 계산을 log 단계로 줄이는 사고를 학습합니다.
- 개념: a^(n/2)를 재사용해 곱셈 횟수를 줄입니다.
- 시간복잡도(필요한 경우): O(log N)
- 핵심 변수 의미: a: 밑, n: 지수, half: 절반 지수 결과
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 2^10=1024 출력으로 분할정복의 효율을 이해할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>

long long power_recursive(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    long long half = power_recursive(a, n / 2);
    if (n % 2 == 0) return half * half;
    return half * half * a;
}

int main() {
    std::cout << power_recursive(2, 10) << '\n'; }
