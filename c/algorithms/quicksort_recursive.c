#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int partition(int arr[],int l,int r){
    int pivot=arr[r],i=l-1;
    for(int j=l;j<r;j++) if(arr[j]<=pivot) swap(&arr[++i],&arr[j]);
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}
int main(void){
    int arr[]={5,2,9,1,7};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
