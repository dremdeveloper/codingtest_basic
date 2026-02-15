#include <stdio.h>

int gcd_recursive(int a,int b){
    if(b==0) return a;
    return gcd_recursive(b,a%b);
}

int main(void){
    printf("gcd_recursive(48,18) = %d\n", gcd_recursive(48,18));
    return 0;
}
