#include <stdio.h>

long long factorial_recursive(int n){
    if(n<=1) return 1;
    return n*factorial_recursive(n-1);
}

int main(void){
    printf("factorial_recursive(5) = %lld\n", factorial_recursive(5));
    return 0;
}
