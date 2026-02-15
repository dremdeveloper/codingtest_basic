"""팩토리얼 (재귀) 예시."""


def factorial_recursive(n: int) -> int:
    if n < 0:
        raise ValueError("n은 0 이상이어야 합니다.")
    if n <= 1:
        return 1
    return n * factorial_recursive(n - 1)


if __name__ == "__main__":
    print(factorial_recursive(5))  # 120
