/*
- 제목: 피보나치 (재귀)
- 개념: F(n)=F(n-1)+F(n-2)를 그대로 재귀 구현한 교육용 버전입니다.
- 시간복잡도(필요한 경우): O(2^N)
- 주요 변수 의미: n: 계산 인덱스, 기저조건 n<=1
- 실행 흐름 요약:
  1) n<=1이면 n을 반환해 재귀를 멈춥니다.
  2) F(n)=F(n-1)+F(n-2) 공식을 그대로 호출합니다.
  3) 재귀 트리에서 같은 하위 문제가 여러 번 계산됩니다.
  4) 하위 호출 결과가 합쳐져 최종 F(n)이 반환됩니다.
  5) 출력값과 함께 재귀 방식의 비효율성까지 학습할 수 있습니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 10번째 값 55가 출력되며, 동시에 재귀 비효율성도 학습할 수 있습니다.
*/

#include <stdio.h>

long long fibonacci_recursive(int n){
    if(n<=1) return n;
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

int main(void){
    printf("fibonacci_recursive(10) = %lld\n", fibonacci_recursive(10));
    return 0;
}
