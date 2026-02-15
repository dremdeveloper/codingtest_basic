#include <stdio.h>

long long factorial_iterative(int n){
    long long result=1;
    for(int i=2;i<=n;i++) result*=i;
    return result;
}

int main(void){
    printf("factorial_iterative(5) = %lld\n", factorial_iterative(5));
    return 0;
}
