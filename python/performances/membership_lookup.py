"""멤버십 조회: list vs set

- 동작: 특정 값이 컬렉션 안에 있는지 확인
- 차이: list는 O(N), set은 평균 O(1)
"""

from __future__ import annotations

import random
import time


def contains_with_list(data: list[int], queries: list[int]) -> int:
    count = 0
    for q in queries:
        if q in data:  # O(N)
            count += 1
    return count


def contains_with_set(data: list[int], queries: list[int]) -> int:
    data_set = set(data)  # O(N)
    count = 0
    for q in queries:
        if q in data_set:  # 평균 O(1)
            count += 1
    return count


def main() -> None:
    n = 400_000
    q = 200_000
    data = list(range(n))
    queries = [random.randint(0, n * 2) for _ in range(q)]

    s = time.perf_counter()
    c1 = contains_with_list(data, queries)
    t1 = time.perf_counter() - s

    s = time.perf_counter()
    c2 = contains_with_set(data, queries)
    t2 = time.perf_counter() - s

    print(f"list 결과={c1}, 시간={t1:.4f}s")
    print(f"set  결과={c2}, 시간={t2:.4f}s")


if __name__ == "__main__":
    main()
