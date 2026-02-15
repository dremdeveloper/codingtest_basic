"""DFS (재귀) 예시."""


def dfs_recursive(graph: dict[int, list[int]], start: int, visited: set[int] | None = None) -> list[int]:
    if visited is None:
        visited = set()

    visited.add(start)
    order = [start]

    for nxt in graph[start]:
        if nxt not in visited:
            order.extend(dfs_recursive(graph, nxt, visited))

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
    print(dfs_recursive(graph_data, 1))  # [1, 2, 4, 5, 6, 3]
