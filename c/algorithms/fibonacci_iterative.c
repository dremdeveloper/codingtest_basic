/*
- 제목: 피보나치 (반복)
- 개념: 이전 두 항을 저장하며 순차적으로 n번째 값을 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: a,b: 직전 두 피보나치 값, c: 새로 계산한 값, n: 목표 인덱스
- 실행 흐름 요약:
  1) n<=1인 경우 즉시 n을 반환합니다.
  2) a,b를 이전 두 항으로 두고 반복 준비를 합니다.
  3) 루프에서 c=a+b를 계산하고 a=b, b=c로 상태를 전진시킵니다.
  4) n번째 단계까지 반복 후 b가 정답이 됩니다.
  5) main 출력으로 반복적 상태 갱신 방식을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: fibonacci(10)=55가 출력됩니다.
*/

#include <stdio.h>

long long fibonacci_iterative(int n){
    if(n<=1) return n;
    long long a=0,b=1;
    for(int i=2;i<=n;i++){
        long long c=a+b;
        a=b; b=c;
    }
    return b;
}

int main(void){
    printf("fibonacci_iterative(10) = %lld\n", fibonacci_iterative(10));
    return 0;
}
