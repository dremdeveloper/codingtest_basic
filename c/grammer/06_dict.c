#include <stdio.h>
#include <string.h>
typedef struct{const char*key; int value;} KV;
int main(void){
    KV map[]={{"apple",3},{"banana",5}};
    for(int i=0;i<2;i++) if(strcmp(map[i].key,"banana")==0) printf("%d\n",map[i].value);
    return 0;
}
