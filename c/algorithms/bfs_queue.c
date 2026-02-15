#include <stdio.h>

int main(void){
    int n=5;
    int graph[5][5]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,1},{0,1,1,0,1},{0,0,1,1,0}};
    int visited[5]={0};
    int q[100],front=0,rear=0;
    q[rear++]=0;
    visited[0]=1;
    while(front<rear){
        int v=q[front++];
        printf("%d ",v);
        for(int i=0;i<n;i++) if(graph[v][i] && !visited[i]){ visited[i]=1; q[rear++]=i; }
    }
    printf("\n");
    return 0;
}
