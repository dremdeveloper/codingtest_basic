"""DFS (반복, 스택) 예시."""


def dfs_iterative(graph: dict[int, list[int]], start: int) -> list[int]:
    visited: set[int] = set()
    stack = [start]
    order: list[int] = []

    while stack:
        node = stack.pop()
        if node in visited:
            continue

        visited.add(node)
        order.append(node)

        for nxt in reversed(graph[node]):
            if nxt not in visited:
                stack.append(nxt)

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
    print(dfs_iterative(graph_data, 1))  # [1, 2, 4, 5, 6, 3]
