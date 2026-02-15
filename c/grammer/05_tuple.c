#include <stdio.h>
typedef struct{int x; int y;} Pair;
int main(void){
    Pair p={3,7};
    printf("(%d,%d)\n",p.x,p.y);
    return 0;
}
