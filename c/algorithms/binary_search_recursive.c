/*
- 제목: 이진 탐색 (재귀)
- 개념: 반복 대신 재귀 호출로 구간을 반으로 줄이며 탐색합니다.
- 시간복잡도(필요한 경우): O(log N)
- 주요 변수 의미: arr: 정렬 배열, left/right: 현재 구간 경계, target: 찾을 값, mid: 비교 지점
- 실행 흐름 요약:
  1) 현재 구간 [left,right]를 재귀 함수 인자로 전달합니다.
  2) left>right이면 탐색 실패로 -1을 반환합니다.
  3) mid를 계산해 target과 비교 후 왼쪽/오른쪽 하위 구간으로 재귀 호출합니다.
  4) 기저조건에 도달할 때까지 구간이 절반씩 줄어듭니다.
  5) 최종 반환된 인덱스를 main에서 출력합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: target=7의 인덱스 3을 찾아 출력합니다.
*/

#include <stdio.h>

int binary_search_recursive(int arr[],int left,int right,int target){
    if(left>right) return -1;
    int mid=left+(right-left)/2;
    if(arr[mid]==target) return mid;
    if(arr[mid]<target) return binary_search_recursive(arr,mid+1,right,target);
    return binary_search_recursive(arr,left,mid-1,target);
}

int main(void){
    int arr[]={1,3,5,7,9};
    printf("index=%d\n", binary_search_recursive(arr,0,4,7));
    return 0;
}
