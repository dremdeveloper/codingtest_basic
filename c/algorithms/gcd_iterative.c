#include <stdio.h>

int gcd_iterative(int a,int b){
    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main(void){
    printf("gcd_iterative(48,18) = %d\n", gcd_iterative(48,18));
    return 0;
}
