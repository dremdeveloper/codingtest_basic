"""구간 합 질의: 매번 합산 vs 누적합(prefix sum)

- 동작: 여러 [l, r] 구간의 합을 구함
- 차이:
  * naive: 질의마다 sum(arr[l:r+1]) -> O(K * N)
  * prefix sum: 전처리 O(N) + 질의 O(1) -> O(N + K)
"""

from __future__ import annotations

import random
import time


def range_sum_naive(arr: list[int], queries: list[tuple[int, int]]) -> list[int]:
    return [sum(arr[l : r + 1]) for l, r in queries]


def build_prefix(arr: list[int]) -> list[int]:
    prefix = [0]
    for x in arr:
        prefix.append(prefix[-1] + x)
    return prefix


def range_sum_prefix(prefix: list[int], queries: list[tuple[int, int]]) -> list[int]:
    return [prefix[r + 1] - prefix[l] for l, r in queries]


def main() -> None:
    n = 400_000
    k = 200_000
    arr = [random.randint(1, 100) for _ in range(n)]
    queries: list[tuple[int, int]] = []
    for _ in range(k):
        a = random.randint(0, n - 1)
        b = random.randint(a, n - 1)
        queries.append((a, b))

    s = time.perf_counter()
    naive = range_sum_naive(arr, queries)
    t1 = time.perf_counter() - s

    s = time.perf_counter()
    prefix = build_prefix(arr)
    fast = range_sum_prefix(prefix, queries)
    t2 = time.perf_counter() - s

    print(f"naive 첫 결과={naive[0]}, 시간={t1:.4f}s")
    print(f"prefix 첫 결과={fast[0]}, 시간={t2:.4f}s")


if __name__ == "__main__":
    main()
