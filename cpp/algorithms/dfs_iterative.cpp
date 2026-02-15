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
