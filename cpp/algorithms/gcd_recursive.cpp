/*
- 제목: 최대공약수(재귀)
- 목적: 유클리드 호제법의 재귀 형태를 이해합니다.
- 개념: gcd(a,b)=gcd(b,a%b) 관계를 b==0까지 반복합니다.
- 시간복잡도(필요한 경우): O(log min(a,b))
- 핵심 변수 의미: a/b: 현재 두 수(나머지 연산으로 축소)
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 48,18의 gcd=6 출력으로 호제법의 수렴을 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>

int gcd_recursive(int a, int b) {
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}

int main() {
    std::cout << gcd_recursive(48, 18) << '\n'; }
