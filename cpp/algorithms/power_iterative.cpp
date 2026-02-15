/*
- 제목: 거듭제곱(반복, 이진 지수법)
- 목적: 비트 연산 기반 빠른 거듭제곱을 학습합니다.
- 개념: n의 각 비트를 보며 필요한 경우만 result에 곱합니다.
- 시간복잡도(필요한 경우): O(log N)
- 핵심 변수 의미: result: 누적 답, a: 제곱되며 커지는 밑, n: 처리 중인 지수
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 1024 출력으로 이진 지수법 결과를 검증합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>

long long power_iterative(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n & 1) result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}

int main() {
    std::cout << power_iterative(2, 10) << '\n'; }
