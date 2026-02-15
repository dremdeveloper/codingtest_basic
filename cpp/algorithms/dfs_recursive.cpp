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
