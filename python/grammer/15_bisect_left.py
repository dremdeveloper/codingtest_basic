"""15) bisect_left: 정렬 배열에서 삽입 위치 찾기."""
from bisect import bisect_left, bisect_right

arr = [1, 2, 2, 2, 5]
target = 2

left = bisect_left(arr, target)
right = bisect_right(arr, target)

print("배열:", arr)
print("target의 왼쪽 경계:", left)
print("target 개수:", right - left)
