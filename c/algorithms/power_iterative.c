#include <stdio.h>

long long power_iterative(long long a,long long n){
    long long result=1;
    while(n>0){
        if(n&1) result*=a;
        a*=a;
        n>>=1;
    }
    return result;
}

int main(void){
    printf("power_iterative(2,10) = %lld\n", power_iterative(2,10));
    return 0;
}
