#include <stdio.h>
int lower_bound(int a[],int n,int x){int l=0,r=n;while(l<r){int m=(l+r)/2; if(a[m]<x) l=m+1; else r=m;} return l;}
int main(void){
    int arr[]={1,3,3,5,7};
    printf("idx=%d\n", lower_bound(arr,5,3));
    return 0;
}
