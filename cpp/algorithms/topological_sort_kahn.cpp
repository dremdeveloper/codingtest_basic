/*
- 제목: 위상 정렬(Kahn)
- 목적: 선행/후행 관계가 있는 문제를 정렬하는 방법을 학습합니다.
- 개념: 진입차수(indegree)가 0인 정점을 큐에서 꺼내며 순서를 구성합니다.
- 시간복잡도(필요한 경우): O(V+E)
- 핵심 변수 의미: indegree: 각 정점으로 들어오는 간선 수, q: 진입차수 0 정점 큐, order: 위상 정렬 결과
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 순서가 선행 조건을 만족하는지 확인하며 DAG 개념을 함께 익힐 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topological_sort_kahn(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u) for (int v : graph[u]) indegree[v]++;

    std::queue<int> q;
    for (int i = 0; i < n; ++i) if (indegree[i] == 0) q.push(i);

    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : graph[u]) if (--indegree[v] == 0) q.push(v);
    }
    return order;
}

int main() {
    std::vector<std::vector<int>> graph{{1,2},{3},{3},{}};
    for (int x : topological_sort_kahn(graph)) std::cout << x << ' ';
    std::cout << '\n';
}
