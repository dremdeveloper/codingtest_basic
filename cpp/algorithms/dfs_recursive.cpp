/*
- 제목: DFS(재귀)
- 목적: 깊이 우선 탐색의 재귀 호출 흐름을 이해합니다.
- 개념: 현재 노드를 방문한 뒤, 아직 방문하지 않은 인접 노드로 깊게 들어갑니다.
- 시간복잡도(필요한 경우): O(V+E)
- 핵심 변수 의미: graph: 인접 리스트, visited: 방문 집합, order: 결과 방문 순서
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 순서를 보면 한 경로를 끝까지 탐색한 뒤 되돌아오는 DFS 특성을 배울 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void dfs_impl(const std::unordered_map<int, std::vector<int>>& graph, int node, std::unordered_set<int>& visited, std::vector<int>& order) {
    visited.insert(node);
    order.push_back(node);
    for (int nxt : graph.at(node)) {
        if (!visited.count(nxt)) dfs_impl(graph, nxt, visited, order);
    }
}

std::vector<int> dfs_recursive(const std::unordered_map<int, std::vector<int>>& graph, int start) {
    std::unordered_set<int> visited;
    std::vector<int> order;
    dfs_impl(graph, start, visited, order);
    return order;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph{{1,{2,3}},{2,{4,5}},{3,{6}},{4,{}},{5,{6}},{6,{}}};
    for (int x : dfs_recursive(graph, 1)) std::cout << x << ' ';
    std::cout << '\n';
}
