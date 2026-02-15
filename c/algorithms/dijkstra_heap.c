/*
- 제목: 다익스트라 최단 경로
- 개념: 음수 간선이 없을 때 한 시작점에서 모든 정점까지의 최단거리를 계산합니다.
- 시간복잡도(필요한 경우): O(V^2) (배열 기반 최소 선택)
- 주요 변수 의미: graph: 가중치 인접행렬, dist: 시작점에서의 최소거리, visited: 확정 여부, u: 이번에 확정할 정점
- 실행 흐름 요약:
  1) dist 배열을 INF로 초기화하고 시작 정점(0)만 0으로 설정합니다.
  2) 방문하지 않은 정점 중 dist가 최소인 정점 u를 선택합니다.
  3) u를 확정(visited)한 뒤 u에서 갈 수 있는 인접 정점의 거리를 완화(relax)합니다.
  4) 모든 정점이 확정될 때까지 최소 선택+완화를 반복합니다.
  5) 최종 dist를 출력해 시작점에서 각 정점까지 최단거리를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 출력되는 각 줄은 0 -> i 최단 거리이며, 완화(relaxation) 결과를 확인할 수 있습니다.
*/

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
