/*
- 제목: 거듭제곱 (이진 지수법 반복)
- 개념: 지수의 비트를 이용해 필요한 경우에만 곱하면서 빠르게 거듭제곱합니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: a: 밑, n: 지수, result: 누적 결과
- 실행 흐름 요약:
  1) result=1로 시작하고 (a,n)을 입력으로 받습니다.
  2) n의 최하위 비트가 1이면 result에 현재 a를 곱합니다.
  3) 매 반복마다 a=a*a로 제곱하고 n을 오른쪽 시프트합니다.
  4) n이 0이 되면 누적된 result가 a^n입니다.
  5) main에서 출력해 이진 지수법의 효율을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 2^10 = 1024가 출력됩니다.
*/

#include <stdio.h>

long long power_iterative(long long a,long long n){
    long long result=1;
    while(n>0){
        if(n&1) result*=a;
        a*=a;
        n>>=1;
    }
    return result;
}

int main(void){
    printf("power_iterative(2,10) = %lld\n", power_iterative(2,10));
    return 0;
}
