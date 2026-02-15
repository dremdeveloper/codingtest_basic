/*
- 제목: 문자열 누적 성능
- 개념: strcat를 반복하면 누적 길이만큼 계속 스캔해 비효율이 커질 수 있음을 보여줍니다.
- 시간복잡도(필요한 경우): 반복 strcat는 누적 비용 증가(대체로 O(N^2) 경향)
- 주요 변수 의미: N: 반복 횟수, buf: 결과 문자열 버퍼, s/e: 시작·종료 시각
- 실행 흐름 요약:
  1) 빈 버퍼 buf와 반복 횟수 N을 준비합니다.
  2) 루프에서 strcat으로 문자열을 반복 연결합니다.
  3) 연결이 길어질수록 뒤에 붙일 위치 탐색 비용이 커집니다.
  4) 시작/종료 시각으로 전체 시간을 계산합니다.
  5) 최종 길이와 시간 출력으로 비효율적 결합 패턴을 학습합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 최종 길이와 시간을 통해 문자열 결합 방식의 성능 차이를 학습할 수 있습니다.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void){
    const int N=50000;
    char buf[60000]="";
    clock_t s=clock();
    for(int i=0;i<N;i++) strcat(buf,"a");
    clock_t e=clock();
    printf("strcat 반복 길이=%zu, time=%.4f sec\n", strlen(buf),(double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
