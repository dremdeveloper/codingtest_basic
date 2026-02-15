/*
- 제목: DFS (재귀)
- 개념: 현재 정점을 방문한 뒤 인접한 미방문 정점으로 재귀적으로 깊게 들어갑니다.
- 시간복잡도(필요한 경우): O(V^2) (인접행렬 기준)
- 주요 변수 의미: graph: 인접행렬, visited: 방문 체크 배열, v: 현재 정점, n: 정점 수
- 실행 흐름 요약:
  1) 현재 정점을 방문 처리하고 즉시 출력합니다.
  2) 인접한 정점을 순회하며 미방문 정점을 찾습니다.
  3) 미방문 정점이 있으면 해당 정점으로 재귀 호출해 더 깊이 내려갑니다.
  4) 더 이상 갈 곳이 없으면 호출이 되돌아오며 다음 인접 정점을 처리합니다.
  5) 전체 출력으로 재귀 DFS의 깊이 우선 흐름을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 호출 스택 흐름으로 DFS 방문 순서를 체험할 수 있습니다.
*/

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
