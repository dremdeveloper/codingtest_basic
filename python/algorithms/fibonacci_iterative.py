"""피보나치 수열 (반복) 예시."""


def fibonacci_iterative(n: int) -> int:
    if n < 0:
        raise ValueError("n은 0 이상이어야 합니다.")
    if n <= 1:
        return n

    # a=F(0), b=F(1)에서 시작해서 순차적으로 다음 값을 계산
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b


if __name__ == "__main__":
    print(fibonacci_iterative(10))  # 55
