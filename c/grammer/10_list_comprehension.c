#include <stdio.h>
int main(void){
    int squares[5];
    for(int i=0;i<5;i++) squares[i]=i*i;
    for(int i=0;i<5;i++) printf("%d ",squares[i]);
    printf("\n");
    return 0;
}
