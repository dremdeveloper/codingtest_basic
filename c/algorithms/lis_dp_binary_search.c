/*
- 제목: LIS (이분 탐색 최적화)
- 개념: tails[k]=길이 k+1 증가수열의 최소 끝값을 유지해 LIS 길이를 구합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: nums: 입력 수열, tails: 길이별 최소 끝값, len: 현재 LIS 길이, pos: 삽입 위치
- 실행 흐름 요약:
  1) tails 배열을 빈 상태로 시작하고 len=0으로 둡니다.
  2) 각 수 nums[i]에 대해 tails에서 lower_bound 위치 pos를 찾습니다.
  3) tails[pos]=nums[i]로 갱신해 해당 길이 증가수열의 최소 끝값을 유지합니다.
  4) pos==len이면 새로운 길이가 생긴 것이므로 len을 1 증가시킵니다.
  5) 최종 len을 출력해 LIS 길이를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 예제 LIS 길이 4가 출력됩니다.
*/

#include <stdio.h>

int lower_bound(int arr[],int len,int x){
    int l=0,r=len;
    while(l<r){
        int m=(l+r)/2;
        if(arr[m]<x) l=m+1;
        else r=m;
    }
    return l;
}

int main(void){
    int nums[]={10,20,10,30,20,50};
    int n=6;
    int tails[6],len=0;
    for(int i=0;i<n;i++){
        int pos=lower_bound(tails,len,nums[i]);
        tails[pos]=nums[i];
        if(pos==len) len++;
    }
    printf("LIS length = %d\n", len);
    return 0;
}
