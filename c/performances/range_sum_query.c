/*
- 제목: 구간합 쿼리 성능 비교
- 개념: 쿼리마다 직접 합산하는 방식과 누적합(prefix) 방식의 차이를 비교합니다.
- 시간복잡도(필요한 경우): naive: O(K*R), prefix: O(N+K)
- 주요 변수 의미: arr: 원본 배열, prefix: 누적합 배열, K(쿼리 수): 1000, l/r: 구간 경계
- 실행 흐름 요약:
  1) 배열 arr를 준비하고 naive 구간합 루프 시간을 먼저 측정합니다.
  2) 각 쿼리마다 l~r을 직접 더해 naive 누적값을 계산합니다.
  3) prefix 배열을 구성해 prefix[i+1]=prefix[i]+arr[i]를 만듭니다.
  4) 같은 쿼리를 prefix[r+1]-prefix[l]로 O(1)에 처리합니다.
  5) 두 시간(naive/prefix)을 비교해 누적합 최적화 효과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: naive/prefix 시간이 각각 출력되어 누적합의 이점을 확인할 수 있습니다.
*/

#include <stdio.h>
#include <time.h>

int main(void){
    const int N=100000;
    static int arr[100000],prefix[100001];
    for(int i=0;i<N;i++) arr[i]=i%10;
    clock_t s=clock();
    long long naive=0;
    for(int q=0;q<1000;q++){
        int l=q, r=q+500;
        int sum=0;
        for(int i=l;i<=r;i++) sum+=arr[i];
        naive+=sum;
    }
    clock_t m=clock();
    for(int i=0;i<N;i++) prefix[i+1]=prefix[i]+arr[i];
    long long fast=0;
    for(int q=0;q<1000;q++){
        int l=q, r=q+500;
        fast += prefix[r+1]-prefix[l];
    }
    clock_t e=clock();
    printf("naive=%.4f sec, prefix=%.4f sec\n", (double)(m-s)/CLOCKS_PER_SEC, (double)(e-m)/CLOCKS_PER_SEC);
    return 0;
}
