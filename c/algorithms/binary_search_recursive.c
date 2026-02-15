#include <stdio.h>

int binary_search_recursive(int arr[],int left,int right,int target){
    if(left>right) return -1;
    int mid=left+(right-left)/2;
    if(arr[mid]==target) return mid;
    if(arr[mid]<target) return binary_search_recursive(arr,mid+1,right,target);
    return binary_search_recursive(arr,left,mid-1,target);
}

int main(void){
    int arr[]={1,3,5,7,9};
    printf("index=%d\n", binary_search_recursive(arr,0,4,7));
    return 0;
}
