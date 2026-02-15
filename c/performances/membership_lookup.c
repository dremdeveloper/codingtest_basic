#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool in_list(int arr[],int n,int x){
    for(int i=0;i<n;i++) if(arr[i]==x) return true;
    return false;
}

int main(void){
    int arr[100000];
    for(int i=0;i<100000;i++) arr[i]=i;
    clock_t s=clock();
    int found=0;
    for(int q=0;q<50000;q++) if(in_list(arr,100000,q*2)) found++;
    clock_t e=clock();
    printf("list 유사 탐색 found=%d, time=%.4f sec\n", found, (double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
