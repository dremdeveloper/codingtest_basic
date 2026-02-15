#include <stdio.h>

int main(void){
    int n=6;
    int graph[6][6]={{0,0,1,0,0,0},{0,0,1,1,0,0},{0,0,0,1,0,0},{0,0,0,0,1,1},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    int indeg[6]={0};
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(graph[i][j]) indeg[j]++;
    int q[100],front=0,rear=0;
    for(int i=0;i<n;i++) if(indeg[i]==0) q[rear++]=i;
    while(front<rear){
        int u=q[front++];
        printf("%d ",u);
        for(int v=0;v<n;v++) if(graph[u][v]) if(--indeg[v]==0) q[rear++]=v;
    }
    printf("\n");
    return 0;
}
