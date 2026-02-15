#include <stdio.h>
#include <stdbool.h>

int main(void){
    int arr[]={1,3,2,3,5,1,7,2,9};
    bool seen[100]={0};
    printf("deduplicated: ");
    for(int i=0;i<9;i++) if(!seen[arr[i]]){ seen[arr[i]]=true; printf("%d ",arr[i]); }
    printf("\n");
    return 0;
}
