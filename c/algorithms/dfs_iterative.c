/*
- 제목: DFS (반복/스택)
- 개념: 스택으로 재귀를 대체해 깊이 우선으로 정점을 방문합니다.
- 시간복잡도(필요한 경우): O(V^2) (인접행렬 기준)
- 주요 변수 의미: graph: 인접행렬, stack/top: DFS 스택, visited: 방문 체크, v: 현재 정점
- 실행 흐름 요약:
  1) 시작 정점을 스택에 push합니다.
  2) 스택에서 pop한 정점이 미방문이면 방문 처리 후 출력합니다.
  3) 인접 정점을 스택에 push하여 더 깊은 경로를 우선 탐색하도록 만듭니다.
  4) 스택이 빌 때까지 반복하여 모든 연결 정점을 방문합니다.
  5) 출력 순서를 보고 스택 기반 DFS 동작을 이해합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 출력 순서는 스택에 넣는 순서(여기서는 역순 push)의 영향을 받는 DFS 결과입니다.
*/

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
