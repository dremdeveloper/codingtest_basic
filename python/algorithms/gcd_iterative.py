"""최대공약수 GCD (반복, 유클리드 호제법) 예시."""


def gcd_iterative(a: int, b: int) -> int:
    a, b = abs(a), abs(b)

    # 나머지가 0이 될 때까지 반복
    while b:
        a, b = b, a % b

    return a


if __name__ == "__main__":
    print(gcd_iterative(48, 18))  # 6
