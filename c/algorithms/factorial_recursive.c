/*
- 제목: 팩토리얼 (재귀)
- 개념: n! = n*(n-1)! 점화식을 재귀로 구현합니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: n: 현재 계산 대상, 기저조건 n<=1
- 실행 흐름 요약:
  1) n<=1이면 1을 반환하는 기저조건을 확인합니다.
  2) 기저조건이 아니면 n * factorial(n-1)을 계산합니다.
  3) 재귀가 가장 깊은 단계까지 내려간 뒤 역순으로 곱셈이 누적됩니다.
  4) 최상위 호출이 n! 값을 반환합니다.
  5) main 출력값으로 재귀 점화식 동작을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 5! = 120 이 출력됩니다.
*/

#include <stdio.h>

long long factorial_recursive(int n){
    if(n<=1) return 1;
    return n*factorial_recursive(n-1);
}

int main(void){
    printf("factorial_recursive(5) = %lld\n", factorial_recursive(5));
    return 0;
}
