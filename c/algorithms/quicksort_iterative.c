/*
- 제목: 퀵 정렬 (반복)
- 개념: 재귀 대신 스택으로 구간을 관리하며 partition을 반복합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 주요 변수 의미: stack/top: 처리할 구간 스택, l/r: 현재 구간, p: 피벗 최종 위치
- 실행 흐름 요약:
  1) 초기 구간 [0,n-1]을 스택에 넣습니다.
  2) 구간을 꺼내 partition으로 피벗 위치 p를 확정합니다.
  3) 왼쪽 구간 [l,p-1], 오른쪽 구간 [p+1,r]이 유효하면 스택에 다시 넣습니다.
  4) 스택이 빌 때까지 반복해 모든 구간을 정렬합니다.
  5) 출력 배열로 반복형 퀵정렬 완료를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 정렬된 오름차순 결과가 출력됩니다.
*/

#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int partition(int arr[],int l,int r){
    int pivot=arr[r],i=l-1;
    for(int j=l;j<r;j++) if(arr[j]<=pivot) swap(&arr[++i],&arr[j]);
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

int main(void){
    int arr[]={5,2,9,1,7};
    int stack[10],top=-1;
    stack[++top]=0; stack[++top]=4;
    while(top>=1){
        int r=stack[top--], l=stack[top--];
        int p=partition(arr,l,r);
        if(p-1>l){ stack[++top]=l; stack[++top]=p-1; }
        if(p+1<r){ stack[++top]=p+1; stack[++top]=r; }
    }
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
