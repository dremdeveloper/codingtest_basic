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
