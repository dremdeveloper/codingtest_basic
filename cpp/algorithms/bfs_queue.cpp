/*
- 제목: BFS(큐)
- 목적: 그래프에서 시작점 기준 가까운 순서(레벨 순서) 방문을 학습합니다.
- 개념: queue에 넣고 꺼내며 인접 정점을 확장하는 너비 우선 탐색입니다.
- 시간복잡도(필요한 경우): O(V+E) (V: 정점 수, E: 간선 수)
- 핵심 변수 의미: graph: 인접 리스트, start: 시작 정점, visited: 중복 방문 방지 집합, q: 탐색 큐, order: 방문 순서
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 순서로 레벨 탐색 특성을 확인할 수 있습니다(가까운 정점이 먼저 나옴). 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> bfs(const std::unordered_map<int, std::vector<int>>& graph, int start) {
    std::unordered_set<int> visited{start};
    std::queue<int> q;
    q.push(start);
    std::vector<int> order;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int nxt : graph.at(node)) {
            if (!visited.count(nxt)) {
                visited.insert(nxt);
                q.push(nxt);
            }
        }
    }
    return order;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph{{1,{2,3}},{2,{4,5}},{3,{6}},{4,{}},{5,{6}},{6,{}}};
    for (int x : bfs(graph, 1)) std::cout << x << ' ';
    std::cout << '\n';
}
