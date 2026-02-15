"""거듭제곱 (반복, 이진 지수법) 예시."""


def power_iterative(base: int, exp: int) -> int:
    if exp < 0:
        raise ValueError("exp는 0 이상이어야 합니다.")

    result = 1
    x = base
    n = exp

    # n의 비트를 오른쪽으로 이동시키며 필요한 제곱 값만 곱합니다.
    while n > 0:
        if n & 1:
            result *= x
        x *= x
        n >>= 1

    return result


if __name__ == "__main__":
    print(power_iterative(2, 10))  # 1024
