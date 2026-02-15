"""거듭제곱 (재귀, 분할 정복) 예시."""


def power_recursive(base: int, exp: int) -> int:
    if exp < 0:
        raise ValueError("exp는 0 이상이어야 합니다.")

    # 기저 사례
    if exp == 0:
        return 1
    if exp == 1:
        return base

    # 절반 지수를 재활용해 연산 횟수를 줄입니다.
    half = power_recursive(base, exp // 2)
    if exp % 2 == 0:
        return half * half
    return half * half * base


if __name__ == "__main__":
    print(power_recursive(2, 10))  # 1024
