#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void){
    const int N=50000;
    char buf[60000]="";
    clock_t s=clock();
    for(int i=0;i<N;i++) strcat(buf,"a");
    clock_t e=clock();
    printf("strcat 반복 길이=%zu, time=%.4f sec\n", strlen(buf),(double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
