"""17) 함수: 입력값을 받아 결과를 반환하는 구조."""

def gcd(a: int, b: int) -> int:
    """유클리드 호제법으로 최대공약수 계산."""
    while b:
        a, b = b, a % b
    return a

x, y = 12, 18
print(f"gcd({x}, {y}) =", gcd(x, y))
