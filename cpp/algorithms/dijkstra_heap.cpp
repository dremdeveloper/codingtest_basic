/*
- 제목: 다익스트라(우선순위 큐)
- 목적: 가중치 그래프 최단경로 기본 알고리즘을 익힙니다.
- 개념: 현재까지 거리 최솟값 정점을 힙에서 꺼내 간선을 완화(relaxation)합니다.
- 시간복잡도(필요한 경우): O((V+E) log V)
- 핵심 변수 의미: dist: 시작점에서 각 정점까지 최단거리, pq: (거리,정점) 최소 힙, weight: 간선 가중치
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 정점:거리 출력으로 각 노드의 최단거리 결과를 해석하고 완화 개념을 이해할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

using P = std::pair<int, int>;

std::unordered_map<int, int> dijkstra(const std::unordered_map<int, std::vector<P>>& graph, int start) {
    const int INF = std::numeric_limits<int>::max();
    std::unordered_map<int, int> dist;
    for (auto& [node, _] : graph) dist[node] = INF;
    dist[start] = 0;

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, node] = pq.top(); pq.pop();
        if (cur_dist > dist[node]) continue;

        for (auto [nxt, weight] : graph.at(node)) {
            if (cur_dist + weight < dist[nxt]) {
                dist[nxt] = cur_dist + weight;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

int main() {
    std::unordered_map<int, std::vector<P>> g{{1,{{2,2},{3,5}}},{2,{{3,1},{4,2}}},{3,{{4,3},{5,1}}},{4,{{5,2}}},{5,{}}};
    auto dist = dijkstra(g, 1);
    for (int i = 1; i <= 5; ++i) std::cout << i << ':' << dist[i] << ' ';
    std::cout << '\n';
}
