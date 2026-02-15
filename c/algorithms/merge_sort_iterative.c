#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

int main(void){
    int arr[]={5,2,9,1,7};
    int n=5;
    for(int size=1; size<n; size*=2){
        for(int left=0; left<n-1; left+=2*size){
            int mid=left+size-1;
            int right=left+2*size-1;
            if(mid>=n-1) continue;
            if(right>=n) right=n-1;
            merge(arr,left,mid,right);
        }
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
