/*
- 제목: 최대공약수 (재귀 유클리드)
- 개념: gcd(a,b)=gcd(b,a%b), b==0이면 종료하는 재귀 형태입니다.
- 시간복잡도(필요한 경우): O(log min(a,b))
- 주요 변수 의미: a,b: 현재 두 수
- 실행 흐름 요약:
  1) 재귀 시작 시 b==0인지 확인합니다.
  2) b==0이면 현재 a를 최대공약수로 반환합니다.
  3) 아니면 gcd(b, a%b)를 재귀 호출합니다.
  4) 나머지가 0이 될 때까지 호출이 이어집니다.
  5) 최종 반환값을 출력해 재귀 유클리드 과정을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: gcd(48,18)=6이 출력됩니다.
*/

#include <stdio.h>

int gcd_recursive(int a,int b){
    if(b==0) return a;
    return gcd_recursive(b,a%b);
}

int main(void){
    printf("gcd_recursive(48,18) = %d\n", gcd_recursive(48,18));
    return 0;
}
