#include <stdio.h>

int lower_bound(int arr[],int len,int x){
    int l=0,r=len;
    while(l<r){
        int m=(l+r)/2;
        if(arr[m]<x) l=m+1;
        else r=m;
    }
    return l;
}

int main(void){
    int nums[]={10,20,10,30,20,50};
    int n=6;
    int tails[6],len=0;
    for(int i=0;i<n;i++){
        int pos=lower_bound(tails,len,nums[i]);
        tails[pos]=nums[i];
        if(pos==len) len++;
    }
    printf("LIS length = %d\n", len);
    return 0;
}
