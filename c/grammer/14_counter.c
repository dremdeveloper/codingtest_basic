#include <stdio.h>
int main(void){
    int arr[]={1,1,2,3,2,1},cnt[10]={0};
    for(int i=0;i<6;i++) cnt[arr[i]]++;
    for(int i=0;i<10;i++) if(cnt[i]) printf("%d:%d ",i,cnt[i]);
    printf("\n");
    return 0;
}
