"""5) 튜플: 변경 불가능한(immutable) 자료형."""

point = (3, 7)

# 좌표처럼 고정된 데이터를 표현할 때 유용합니다.
x, y = point
print("튜플 원본:", point)
print("언패킹 결과 x, y:", x, y)
print("튜플 길이:", len(point))
