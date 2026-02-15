"""팩토리얼 (반복) 예시."""


def factorial_iterative(n: int) -> int:
    if n < 0:
        raise ValueError("n은 0 이상이어야 합니다.")

    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


if __name__ == "__main__":
    print(factorial_iterative(5))  # 120
