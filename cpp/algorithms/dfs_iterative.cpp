/*
- 제목: DFS(반복, 스택)
- 목적: 재귀 DFS를 스택 자료구조로 직접 구현하는 방법을 학습합니다.
- 개념: stack의 LIFO 특성을 이용해 깊이 우선 탐색을 수행합니다.
- 시간복잡도(필요한 경우): O(V+E)
- 핵심 변수 의미: st: 탐색 스택, visited: 방문 집합, order: 방문 결과
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 재귀 없이도 DFS가 동일 원리로 동작함을 방문 순서로 확인할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> dfs_iterative(const std::unordered_map<int, std::vector<int>>& graph, int start) {
    std::unordered_set<int> visited;
    std::stack<int> st;
    st.push(start);
    std::vector<int> order;

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited.count(node)) continue;
        visited.insert(node);
        order.push_back(node);

        auto next = graph.at(node);
        std::reverse(next.begin(), next.end());
        for (int nxt : next) if (!visited.count(nxt)) st.push(nxt);
    }
    return order;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph{{1,{2,3}},{2,{4,5}},{3,{6}},{4,{}},{5,{6}},{6,{}}};
    for (int x : dfs_iterative(graph, 1)) std::cout << x << ' ';
    std::cout << '\n';
}
