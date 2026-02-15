/*
- 제목: 최대공약수(반복)
- 목적: 유클리드 호제법을 while 루프로 구현합니다.
- 개념: (a,b)를 (b,a%b)로 갱신하며 b가 0이 되면 종료합니다.
- 시간복잡도(필요한 경우): O(log min(a,b))
- 핵심 변수 의미: a/b: 현재 비교 중인 두 수
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 6 출력으로 반복 구현도 재귀와 동일 결과를 냄을 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>

int gcd_iterative(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    std::cout << gcd_iterative(48, 18) << '\n'; }
