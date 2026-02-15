#include <stdio.h>
#include <limits.h>
#define N 5

int main(void){
    int graph[N][N]={{0,2,5,0,0},{2,0,3,4,0},{5,3,0,2,3},{0,4,2,0,1},{0,0,3,1,0}};
    int dist[N],visited[N]={0};
    for(int i=0;i<N;i++) dist[i]=INT_MAX;
    dist[0]=0;
    for(int k=0;k<N;k++){
        int u=-1,min=INT_MAX;
        for(int i=0;i<N;i++) if(!visited[i]&&dist[i]<min){min=dist[i];u=i;}
        if(u==-1) break;
        visited[u]=1;
        for(int v=0;v<N;v++) if(graph[u][v] && dist[u]!=INT_MAX && dist[v]>dist[u]+graph[u][v]) dist[v]=dist[u]+graph[u][v];
    }
    for(int i=0;i<N;i++) printf("0 -> %d : %d\n",i,dist[i]);
    return 0;
}
