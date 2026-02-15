/*
- 제목: BFS (너비 우선 탐색)
- 개념: 큐를 사용해 시작 정점에서 가까운 정점(레벨)부터 순서대로 방문합니다.
- 시간복잡도(필요한 경우): O(V^2) (인접행렬 기준)
- 주요 변수 의미: graph: 인접행렬, visited: 방문 체크, q/front/rear: BFS 큐, v: 현재 정점
- 실행 흐름 요약:
  1) 시작 정점(0)을 큐에 넣고 visited를 표시합니다.
  2) 큐에서 정점을 하나 꺼내 방문 순서에 출력합니다.
  3) 해당 정점과 연결된 인접 정점 중 미방문 노드를 찾아 큐에 넣고 방문 처리합니다.
  4) 큐가 빌 때까지 반복하여 레벨 순 방문을 완성합니다.
  5) 출력 순서를 통해 BFS의 너비 우선 특성을 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 출력 순서는 그래프 구조에서 레벨 순 방문 결과를 보여주므로 BFS 개념 확인에 좋습니다.
*/

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
