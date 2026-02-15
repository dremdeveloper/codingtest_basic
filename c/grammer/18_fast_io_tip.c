#include <stdio.h>
int main(void){
    setvbuf(stdin, NULL, _IOFBF, 1<<20);
    setvbuf(stdout, NULL, _IOFBF, 1<<20);
    printf("fast io buffer set\n");
    fflush(stdout);
    return 0;
}
