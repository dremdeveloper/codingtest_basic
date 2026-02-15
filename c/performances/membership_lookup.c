/*
- 제목: 멤버십 조회 성능
- 개념: 선형 탐색(in_list) 방식의 포함 여부 확인 비용을 체감하는 예시입니다.
- 시간복잡도(필요한 경우): O(Q*N)
- 주요 변수 의미: arr: 탐색 대상 데이터, q: 질의 값, found: 찾은 횟수
- 실행 흐름 요약:
  1) 큰 배열 arr를 생성해 탐색 대상 데이터를 준비합니다.
  2) 각 질의 q에 대해 in_list(선형 탐색)를 수행합니다.
  3) 발견되면 found를 증가시켜 실제 매칭 횟수를 집계합니다.
  4) clock으로 시작/종료 시간을 재어 총 소요 시간을 계산합니다.
  5) found와 시간을 출력해 선형 탐색 비용을 체감합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: found 값과 실행 시간이 출력되어 많은 질의에서 선형 탐색이 느릴 수 있음을 보여줍니다.
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool in_list(int arr[],int n,int x){
    for(int i=0;i<n;i++) if(arr[i]==x) return true;
    return false;
}

int main(void){
    int arr[100000];
    for(int i=0;i<100000;i++) arr[i]=i;
    clock_t s=clock();
    int found=0;
    for(int q=0;q<50000;q++) if(in_list(arr,100000,q*2)) found++;
    clock_t e=clock();
    printf("list 유사 탐색 found=%d, time=%.4f sec\n", found, (double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
