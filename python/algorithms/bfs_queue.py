"""BFS (큐) 예시."""

from collections import deque


def bfs(graph: dict[int, list[int]], start: int) -> list[int]:
    visited = {start}
    queue = deque([start])
    order: list[int] = []

    while queue:
        node = queue.popleft()
        order.append(node)

        for nxt in graph[node]:
            if nxt not in visited:
                visited.add(nxt)
                queue.append(nxt)

    return order


if __name__ == "__main__":
    graph_data = {
        1: [2, 3],
        2: [4, 5],
        3: [6],
        4: [],
        5: [6],
        6: [],
    }
    print(bfs(graph_data, 1))  # [1, 2, 3, 4, 5, 6]
