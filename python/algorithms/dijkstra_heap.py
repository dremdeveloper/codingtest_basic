"""다익스트라 최단 경로 (우선순위 큐) 예시."""

import heapq


INF = 10**15


def dijkstra(graph: dict[int, list[tuple[int, int]]], start: int) -> dict[int, int]:
    # 시작점으로부터 각 정점까지의 현재 최단 거리
    dist = {node: INF for node in graph}
    dist[start] = 0

    # (거리, 정점) 형태의 최소 힙
    pq: list[tuple[int, int]] = [(0, start)]

    while pq:
        cur_dist, node = heapq.heappop(pq)

        # 힙에서 꺼낸 정보가 오래된 값이면 무시
        if cur_dist > dist[node]:
            continue

        # 인접 정점 완화(relaxation)
        for nxt, weight in graph[node]:
            cand = cur_dist + weight
            if cand < dist[nxt]:
                dist[nxt] = cand
                heapq.heappush(pq, (cand, nxt))

    return dist


if __name__ == "__main__":
    # (도착 정점, 가중치)
    weighted_graph = {
        1: [(2, 2), (3, 5)],
        2: [(3, 1), (4, 2)],
        3: [(4, 3), (5, 1)],
        4: [(5, 2)],
        5: [],
    }
    print(dijkstra(weighted_graph, 1))  # {1:0, 2:2, 3:3, 4:4, 5:4}
