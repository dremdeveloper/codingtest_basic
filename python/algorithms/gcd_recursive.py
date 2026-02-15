"""최대공약수 GCD (재귀, 유클리드 호제법) 예시."""


def gcd_recursive(a: int, b: int) -> int:
    # 음수 입력도 처리할 수 있도록 절대값으로 변환
    a, b = abs(a), abs(b)

    # b가 0이면 a가 최대공약수
    if b == 0:
        return a

    # gcd(a, b) = gcd(b, a % b)
    return gcd_recursive(b, a % b)


if __name__ == "__main__":
    print(gcd_recursive(48, 18))  # 6
