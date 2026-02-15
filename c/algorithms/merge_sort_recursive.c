/*
- 제목: 병합 정렬 (재귀)
- 개념: 배열을 반으로 나누고 정렬 후 병합하는 분할정복 알고리즘입니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: l/r/m: 구간 경계, L/R: 병합용 임시 배열
- 실행 흐름 요약:
  1) 현재 구간을 mid 기준으로 좌/우 절반으로 분할합니다.
  2) 좌측과 우측 구간을 각각 재귀적으로 정렬합니다.
  3) 정렬된 두 구간을 merge로 합쳐 하나의 정렬 구간을 만듭니다.
  4) 호출이 되돌아오며 더 큰 구간들이 순차적으로 정렬됩니다.
  5) 최종 출력으로 분할정복 정렬 결과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 오름차순 정렬 결과가 출력됩니다.
*/

#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void merge_sort(int arr[],int l,int r){
    if(l>=r) return;
    int m=l+(r-l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main(void){
    int arr[]={5,2,9,1,7};
    merge_sort(arr,0,4);
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
