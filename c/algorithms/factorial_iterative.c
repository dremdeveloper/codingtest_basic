/*
- 제목: 팩토리얼 (반복)
- 개념: 1부터 n까지의 곱을 누적해 n! 값을 계산합니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: n: 입력 정수, result: 누적 곱
- 실행 흐름 요약:
  1) result를 1로 초기화합니다.
  2) i=2부터 n까지 순회하며 result에 i를 곱해 누적합니다.
  3) 반복이 끝나면 n! 계산이 완료됩니다.
  4) 함수 반환값을 main에서 받아 출력합니다.
  5) 작은 입력으로 직접 검산하며 곱셈 누적 패턴을 익힙니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 5! = 120 이 출력됩니다.
*/

#include <stdio.h>

long long factorial_iterative(int n){
    long long result=1;
    for(int i=2;i<=n;i++) result*=i;
    return result;
}

int main(void){
    printf("factorial_iterative(5) = %lld\n", factorial_iterative(5));
    return 0;
}
