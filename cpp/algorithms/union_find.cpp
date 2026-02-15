#include <iostream>
#include <vector>

std::vector<int> make_parent(int n) {
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    return parent;
}

int find(std::vector<int>& parent, int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

bool unite(std::vector<int>& parent, std::vector<int>& rank, int a, int b) {
    int ra = find(parent, a), rb = find(parent, b);
    if (ra == rb) return false;
    if (rank[ra] < rank[rb]) parent[ra] = rb;
    else if (rank[ra] > rank[rb]) parent[rb] = ra;
    else { parent[rb] = ra; rank[ra]++; }
    return true;
}

int main() {
    auto parent = make_parent(7);
    std::vector<int> rank(7, 0);
    unite(parent, rank, 1, 2);
    unite(parent, rank, 2, 3);
    unite(parent, rank, 4, 5);

    std::cout << (find(parent,1) == find(parent,3)) << '\n';
    std::cout << (find(parent,1) == find(parent,5)) << '\n';
}
