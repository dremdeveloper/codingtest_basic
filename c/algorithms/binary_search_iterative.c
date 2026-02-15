#include <stdio.h>

int binary_search_iterative(int arr[],int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int main(void){
    int arr[]={1,3,5,7,9};
    printf("index=%d\n", binary_search_iterative(arr,5,7));
    return 0;
}
