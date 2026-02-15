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
