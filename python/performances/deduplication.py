"""중복 제거: 리스트 순회 중 in 검사 vs set 활용

- 동작: 원소 순서를 유지하며 중복 제거
- 차이:
  * naive: result 리스트에 in 검사 -> O(N^2)
  * set 보조: seen set에 검사 -> 평균 O(N)
"""

from __future__ import annotations

import random
import time


def dedup_naive(nums: list[int]) -> list[int]:
    result: list[int] = []
    for x in nums:
        if x not in result:  # O(N)
            result.append(x)
    return result


def dedup_with_set(nums: list[int]) -> list[int]:
    result: list[int] = []
    seen: set[int] = set()
    for x in nums:
        if x not in seen:  # 평균 O(1)
            seen.add(x)
            result.append(x)
    return result


def main() -> None:
    n = 600_000
    nums = [random.randint(1, 30_000) for _ in range(n)]

    s = time.perf_counter()
    a = dedup_naive(nums)
    t1 = time.perf_counter() - s

    s = time.perf_counter()
    b = dedup_with_set(nums)
    t2 = time.perf_counter() - s

    print(f"naive 고유개수={len(a)}, 시간={t1:.4f}s")
    print(f"set   고유개수={len(b)}, 시간={t2:.4f}s")


if __name__ == "__main__":
    main()
