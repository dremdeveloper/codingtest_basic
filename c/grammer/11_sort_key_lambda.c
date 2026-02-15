#include <stdio.h>
#include <stdlib.h>
typedef struct{const char*name; int score;} Item;
int cmp(const void*a,const void*b){return ((Item*)b)->score-((Item*)a)->score;}
int main(void){
    Item arr[]={{"kim",80},{"lee",95},{"park",70}};
    qsort(arr,3,sizeof(Item),cmp);
    for(int i=0;i<3;i++) printf("%s %d\n",arr[i].name,arr[i].score);
    return 0;
}
