/*
- 제목: 위상 정렬 (Kahn)
- 개념: 진입차수 0 정점을 큐에서 꺼내며 DAG의 선행관계를 만족하는 순서를 만듭니다.
- 시간복잡도(필요한 경우): O(V^2) (인접행렬 기준)
- 주요 변수 의미: indeg: 진입차수 배열, q/front/rear: 처리 큐, u: 현재 꺼낸 정점
- 실행 흐름 요약:
  1) 모든 정점의 진입차수(indeg)를 계산합니다.
  2) 진입차수 0인 정점을 큐에 넣어 시작합니다.
  3) 큐에서 정점을 꺼내 결과에 출력하고, 그 정점의 간선을 제거합니다.
  4) 간선 제거로 진입차수가 0이 된 정점을 큐에 추가합니다.
  5) 큐 처리 순서가 DAG의 유효한 위상 순서가 됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 출력 순서는 선행 조건을 지키는 학습용 위상 순서입니다.
*/

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
