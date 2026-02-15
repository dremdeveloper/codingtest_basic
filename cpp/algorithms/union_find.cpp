/*
- 제목: 유니온 파인드(서로소 집합)
- 목적: 집합 병합과 같은 집합 판별을 빠르게 처리하는 구조를 학습합니다.
- 개념: find(경로 압축) + union(rank 기준 합치기)로 트리 높이를 억제합니다.
- 시간복잡도(필요한 경우): 거의 O(1) (정확히는 O(α(N)))
- 핵심 변수 의미: parent: 각 원소의 부모(대표), rank: 트리 높이 근사치, a/b: 합칠 원소
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 같은 집합 여부(1/0) 출력으로 union 연산 결과를 직관적으로 확인할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

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
