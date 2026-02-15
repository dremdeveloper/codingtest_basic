/*
- 제목: 0/1 배낭 문제 (DP)
- 개념: 각 아이템을 넣거나/안 넣거나 선택해 제한 무게에서 최대 가치를 구합니다.
- 시간복잡도(필요한 경우): O(N*W)
- 주요 변수 의미: wt/val: 무게/가치 배열, N: 아이템 수, W: 최대 무게, dp[i][w]: i개 고려·용량w 최대가치
- 실행 흐름 요약:
  1) dp[i][w]를 i개 아이템 고려 시 용량 w의 최대 가치로 정의합니다.
  2) i번째 아이템을 선택하지 않는 값(dp[i-1][w])을 기본값으로 둡니다.
  3) 용량이 허용되면 선택하는 경우(dp[i-1][w-wt]+val)와 비교합니다.
  4) 둘 중 큰 값을 dp[i][w]에 저장해 표를 채웁니다.
  5) 마지막 dp[n][W]를 출력해 최적해를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: dp[N][W]가 최적해(최대 가치)로 출력됩니다.
*/

#include <stdio.h>

int max(int a,int b){return a>b?a:b;}

int main(void){
    int wt[]={2,1,3,2};
    int val[]={12,10,20,15};
    int n=4,W=5;
    int dp[5+1][5+1]={0};
    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            dp[i][w]=dp[i-1][w];
            if(w>=wt[i-1]) dp[i][w]=max(dp[i][w],dp[i-1][w-wt[i-1]]+val[i-1]);
        }
    }
    printf("max value = %d\n", dp[n][W]);
    return 0;
}
