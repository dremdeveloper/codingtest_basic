#include <stdio.h>

long long fibonacci_recursive(int n){
    if(n<=1) return n;
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

int main(void){
    printf("fibonacci_recursive(10) = %lld\n", fibonacci_recursive(10));
    return 0;
}
