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
