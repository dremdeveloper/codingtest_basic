/*
- 제목: 병합 정렬 (반복 Bottom-Up)
- 개념: 부분 배열 크기를 1,2,4...로 키우며 인접 구간을 병합합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 주요 변수 의미: size: 현재 부분배열 크기, left/mid/right: 병합 구간 경계
- 실행 흐름 요약:
  1) size=1부터 시작해 병합할 부분배열 크기를 단계적으로 2배씩 키웁니다.
  2) 각 단계에서 [left..mid], [mid+1..right] 인접 구간을 순차 병합합니다.
  3) merge 함수에서 임시 배열로 두 구간을 안정적으로 합칩니다.
  4) size가 배열 길이 이상이 되면 전체 정렬이 완료됩니다.
  5) main에서 정렬 결과를 출력해 단계적 병합 효과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 정렬 전 [5,2,9,1,7]이 오름차순으로 출력됩니다.
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

int main(void){
    int arr[]={5,2,9,1,7};
    int n=5;
    for(int size=1; size<n; size*=2){
        for(int left=0; left<n-1; left+=2*size){
            int mid=left+size-1;
            int right=left+2*size-1;
            if(mid>=n-1) continue;
            if(right>=n) right=n-1;
            merge(arr,left,mid,right);
        }
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
