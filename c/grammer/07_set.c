#include <stdio.h>
#include <stdbool.h>
int main(void){
    int arr[]={1,2,2,3,1}; bool seen[10]={0};
    for(int i=0;i<5;i++) if(!seen[arr[i]]){seen[arr[i]]=1; printf("%d ",arr[i]);}
    printf("\n");
    return 0;
}
