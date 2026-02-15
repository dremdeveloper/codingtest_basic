/*
- 제목: 최대공약수 (반복 유클리드)
- 개념: (a,b)를 (b,a%b)로 바꾸는 과정을 반복해 GCD를 구합니다.
- 시간복잡도(필요한 경우): O(log min(a,b))
- 주요 변수 의미: a,b: 현재 두 수, t: 나머지 임시 저장
- 실행 흐름 요약:
  1) 두 수 a,b를 준비합니다.
  2) b가 0이 아닐 동안 a%b를 임시값으로 계산합니다.
  3) a=b, b=t로 갱신해 더 작은 문제로 바꿉니다.
  4) b가 0이 되면 a가 최대공약수입니다.
  5) main 출력으로 유클리드 알고리즘 수렴을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: gcd(48,18)=6이 출력됩니다.
*/

#include <stdio.h>

int gcd_iterative(int a,int b){
    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main(void){
    printf("gcd_iterative(48,18) = %d\n", gcd_iterative(48,18));
    return 0;
}
