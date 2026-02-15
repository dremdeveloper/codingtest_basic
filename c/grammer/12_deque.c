#include <stdio.h>
#define MAX 10
int main(void){
    int dq[MAX],front=MAX/2,rear=MAX/2;
    dq[--front]=1; dq[--front]=2; dq[rear++]=3;
    while(front<rear) printf("%d ",dq[front++]);
    printf("\n");
    return 0;
}
