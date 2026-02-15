#include <stdio.h>

void dfs_recursive(int n,int graph[n][n],int v,int visited[]){
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++) if(graph[v][i] && !visited[i]) dfs_recursive(n,graph,i,visited);
}

int main(void){
    int n=5;
    int graph[5][5]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,1},{0,1,1,0,1},{0,0,1,1,0}};
    int visited[5]={0};
    dfs_recursive(n,graph,0,visited);
    printf("\n");
    return 0;
}
