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
