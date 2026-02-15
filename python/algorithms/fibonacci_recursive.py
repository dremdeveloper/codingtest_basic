"""피보나치 수열 (재귀) 예시."""


def fibonacci_recursive(n: int) -> int:
    # 입력 검증
    if n < 0:
        raise ValueError("n은 0 이상이어야 합니다.")

    # 기저 사례
    if n <= 1:
        return n

    # 점화식: F(n) = F(n-1) + F(n-2)
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)


if __name__ == "__main__":
    print(fibonacci_recursive(10))  # 55
