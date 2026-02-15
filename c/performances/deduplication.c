/*
- 제목: 중복 제거 (seen 배열)
- 개념: 등장 여부 배열(seen)을 사용해 중복을 제거하는 기본 패턴입니다.
- 시간복잡도(필요한 경우): O(N)
- 주요 변수 의미: arr: 입력 데이터, seen[x]: 값 x가 이미 등장했는지 여부
- 실행 흐름 요약:
  1) seen 배열을 false로 초기화해 값의 등장 여부를 기록할 준비를 합니다.
  2) 입력 배열을 앞에서부터 순회합니다.
  3) 처음 보는 값이면 출력하고 seen[value]=true로 표시합니다.
  4) 이미 본 값이면 건너뛰어 중복 출력을 막습니다.
  5) 최종 출력으로 입력 순서를 유지한 중복 제거 패턴을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 입력 순서를 유지한 중복 제거 결과가 출력됩니다.
*/

#include <stdio.h>
#include <stdbool.h>

int main(void){
    int arr[]={1,3,2,3,5,1,7,2,9};
    bool seen[100]={0};
    printf("deduplicated: ");
    for(int i=0;i<9;i++) if(!seen[arr[i]]){ seen[arr[i]]=true; printf("%d ",arr[i]); }
    printf("\n");
    return 0;
}
