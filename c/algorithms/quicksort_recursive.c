/*
- 제목: 퀵 정렬 (재귀)
- 개념: 피벗 기준 분할 후 좌/우 구간을 재귀 정렬합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 주요 변수 의미: l/r: 정렬 구간 경계, p: partition 결과 인덱스
- 실행 흐름 요약:
  1) 현재 구간 [l,r]에서 partition을 수행해 피벗 위치 p를 얻습니다.
  2) 피벗 기준 왼쪽/오른쪽 부분배열을 분리합니다.
  3) 두 부분배열에 대해 재귀적으로 같은 과정을 반복합니다.
  4) 기저조건(l>=r)에 도달하면 해당 구간 정렬이 끝납니다.
  5) main 출력으로 전체 정렬 결과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 정렬 결과가 오름차순으로 출력됩니다.
*/

#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int partition(int arr[],int l,int r){
    int pivot=arr[r],i=l-1;
    for(int j=l;j<r;j++) if(arr[j]<=pivot) swap(&arr[++i],&arr[j]);
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}
int main(void){
    int arr[]={5,2,9,1,7};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
