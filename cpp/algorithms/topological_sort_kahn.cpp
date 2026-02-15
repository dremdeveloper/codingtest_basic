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
