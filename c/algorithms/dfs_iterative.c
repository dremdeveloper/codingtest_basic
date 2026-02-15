#include <stdio.h>

int main(void){
    int n=5;
    int graph[5][5]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,1},{0,1,1,0,1},{0,0,1,1,0}};
    int visited[5]={0};
    int stack[100],top=-1;
    stack[++top]=0;
    while(top>=0){
        int v=stack[top--];
        if(visited[v]) continue;
        visited[v]=1;
        printf("%d ",v);
        for(int i=n-1;i>=0;i--) if(graph[v][i] && !visited[i]) stack[++top]=i;
    }
    printf("\n");
    return 0;
}
