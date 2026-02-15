"""10) 리스트 컴프리헨션: 필터 + 변환을 한 줄로."""

# 1~10 중 짝수만 골라 제곱한 리스트 만들기
even_squares = [x * x for x in range(1, 11) if x % 2 == 0]

print("짝수 제곱 리스트:", even_squares)
print("원소 개수:", len(even_squares))
