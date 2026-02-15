/*
- 제목: 이진 탐색 (반복)
- 개념: 정렬된 배열에서 탐색 구간을 절반씩 줄여 target 위치를 찾는 탐색 알고리즘입니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: arr: 정렬된 입력 배열, n: 배열 길이, target: 찾을 값, left/right: 현재 탐색 구간, mid: 중간 인덱스
- 실행 흐름 요약:
  1) left=0, right=n-1로 전체 탐색 범위를 잡습니다.
  2) mid를 계산해 arr[mid]와 target을 비교합니다.
  3) 값이 작으면 left=mid+1, 크면 right=mid-1로 범위를 절반으로 줄입니다.
  4) 찾으면 즉시 인덱스를 반환하고, 범위가 역전되면 -1을 반환합니다.
  5) main에서 반환값을 출력해 탐색 성공/실패를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 예제 arr={1,3,5,7,9}에서 target=7 이므로 index=3이 출력됩니다.
*/

#include <stdio.h>

int binary_search_iterative(int arr[],int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int main(void){
    int arr[]={1,3,5,7,9};
    printf("index=%d\n", binary_search_iterative(arr,5,7));
    return 0;
}
