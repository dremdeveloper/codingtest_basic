#include <stdio.h>
int main(void){
    int arr[]={1,2,3,4};
    for(int i=0;i<4;i++) for(int j=i+1;j<4;j++) printf("(%d,%d) ",arr[i],arr[j]);
    printf("\n");
    return 0;
}
