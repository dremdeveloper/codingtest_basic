"""위상 정렬 (Kahn 알고리즘, BFS 기반) 예시."""

from collections import deque


def topological_sort_kahn(graph: dict[int, list[int]]) -> list[int]:
    # 1) 각 정점의 진입 차수(indegree) 계산
    indegree = {node: 0 for node in graph}
    for node in graph:
        for nxt in graph[node]:
            indegree[nxt] += 1

    # 2) 진입 차수가 0인 정점부터 큐에 넣고 시작
    queue = deque([node for node in graph if indegree[node] == 0])
    order: list[int] = []

    while queue:
        node = queue.popleft()
        order.append(node)

        # 현재 정점에서 나가는 간선을 제거한 효과를 냅니다.
        for nxt in graph[node]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                queue.append(nxt)

    # 모든 정점을 방문하지 못했다면 사이클 존재
    if len(order) != len(graph):
        raise ValueError("사이클이 존재하여 위상 정렬이 불가능합니다.")

    return order


if __name__ == "__main__":
    dag = {
        1: [2, 3],
        2: [4],
        3: [4, 5],
        4: [6],
        5: [6],
        6: [],
    }
    print(topological_sort_kahn(dag))
