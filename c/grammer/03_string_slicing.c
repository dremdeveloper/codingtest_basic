#include <stdio.h>
#include <string.h>
int main(void){
    char s[]="python", sub[4];
    strncpy(sub,s+1,3); sub[3]='\0';
    printf("slice=%s\n",sub);
    return 0;
}
