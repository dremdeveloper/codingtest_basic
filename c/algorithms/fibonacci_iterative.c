#include <stdio.h>

long long fibonacci_iterative(int n){
    if(n<=1) return n;
    long long a=0,b=1;
    for(int i=2;i<=n;i++){
        long long c=a+b;
        a=b; b=c;
    }
    return b;
}

int main(void){
    printf("fibonacci_iterative(10) = %lld\n", fibonacci_iterative(10));
    return 0;
}
