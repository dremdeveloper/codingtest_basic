/*
- 제목: 거듭제곱 (분할정복 재귀)
- 개념: a^n을 a^(n/2) 결과 재사용으로 계산합니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: a: 밑, n: 지수, half: 절반 지수 결과
- 실행 흐름 요약:
  1) n==0, n==1 기저조건을 먼저 처리합니다.
  2) half=power(a,n/2)를 한 번만 계산합니다.
  3) n이 짝수면 half*half, 홀수면 half*half*a를 반환합니다.
  4) 재귀 깊이는 로그 수준으로 줄어듭니다.
  5) 출력으로 분할정복 거듭제곱 결과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 2^10 = 1024가 출력됩니다.
*/

#include <stdio.h>

long long power_recursive(long long a,long long n){
    if(n==0) return 1;
    if(n==1) return a;
    long long half=power_recursive(a,n/2);
    if(n%2==0) return half*half;
    return half*half*a;
}

int main(void){
    printf("power_recursive(2,10) = %lld\n", power_recursive(2,10));
    return 0;
}
