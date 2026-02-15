"""유니온 파인드(Disjoint Set Union) 예시 - class 없이 함수형으로 구현."""


def make_sets(size: int) -> tuple[list[int], list[int]]:
    """초기 부모/랭크 배열을 생성합니다."""
    parent = list(range(size))
    rank = [0] * size
    return parent, rank


def find(parent: list[int], x: int) -> int:
    """x가 속한 집합의 대표(root)를 찾습니다. (경로 압축 적용)"""
    if parent[x] != x:
        # 재귀적으로 루트를 찾은 뒤, 바로 루트를 가리키도록 갱신해 탐색을 빠르게 합니다.
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent: list[int], rank: list[int], a: int, b: int) -> bool:
    """a와 b가 속한 집합을 합칩니다. 이미 같은 집합이면 False를 반환합니다."""
    root_a = find(parent, a)
    root_b = find(parent, b)

    if root_a == root_b:
        return False

    # 랭크(트리 높이 추정치)가 낮은 쪽을 높은 쪽 밑으로 붙여 트리 높이 증가를 줄입니다.
    if rank[root_a] < rank[root_b]:
        parent[root_a] = root_b
    elif rank[root_a] > rank[root_b]:
        parent[root_b] = root_a
    else:
        parent[root_b] = root_a
        rank[root_a] += 1

    return True


if __name__ == "__main__":
    # 원소 0~6, 총 7개 집합 생성
    parent_data, rank_data = make_sets(7)

    union(parent_data, rank_data, 1, 2)
    union(parent_data, rank_data, 2, 3)
    union(parent_data, rank_data, 4, 5)

    print(find(parent_data, 1) == find(parent_data, 3))  # True
    print(find(parent_data, 1) == find(parent_data, 5))  # False
