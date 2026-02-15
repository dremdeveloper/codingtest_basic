"""문자열 누적: += 반복 vs ''.join

- 동작: 여러 문자열 조각을 하나의 문자열로 합치기
- 차이: += 반복은 누적 복사로 O(N^2)까지 커질 수 있고,
       join은 한 번에 할당하여 O(N)
"""

from __future__ import annotations

import string
import time


def build_with_plus(chunks: list[str]) -> str:
    result = ""
    for ch in chunks:
        result += ch
    return result


def build_with_join(chunks: list[str]) -> str:
    return "".join(chunks)


def main() -> None:
    chunks = list(string.ascii_letters) * 80_000

    s = time.perf_counter()
    a = build_with_plus(chunks)
    t1 = time.perf_counter() - s

    s = time.perf_counter()
    b = build_with_join(chunks)
    t2 = time.perf_counter() - s

    print(f"+= 길이={len(a)}, 시간={t1:.4f}s")
    print(f"join 길이={len(b)}, 시간={t2:.4f}s")


if __name__ == "__main__":
    main()
