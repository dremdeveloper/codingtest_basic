#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int partition(int arr[],int l,int r){
    int pivot=arr[r],i=l-1;
    for(int j=l;j<r;j++) if(arr[j]<=pivot) swap(&arr[++i],&arr[j]);
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

int main(void){
    int arr[]={5,2,9,1,7};
    int stack[10],top=-1;
    stack[++top]=0; stack[++top]=4;
    while(top>=1){
        int r=stack[top--], l=stack[top--];
        int p=partition(arr,l,r);
        if(p-1>l){ stack[++top]=l; stack[++top]=p-1; }
        if(p+1<r){ stack[++top]=p+1; stack[++top]=r; }
    }
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
