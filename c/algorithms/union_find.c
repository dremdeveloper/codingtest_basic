#include <stdio.h>

int parent[10];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a,int b){
    a=find(a); b=find(b);
    if(a!=b) parent[b]=a;
}

int main(void){
    for(int i=0;i<10;i++) parent[i]=i;
    unite(1,2); unite(2,3);
    printf("1과 3 같은 집합? %s\n", find(1)==find(3)?"YES":"NO");
    return 0;
}
