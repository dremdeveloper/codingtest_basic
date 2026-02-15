"""7) 집합(set): 중복 제거와 빠른 포함 검사."""

nums = [1, 1, 2, 3, 3, 4]
unique_nums = set(nums)

print("원본 리스트:", nums)
print("중복 제거 결과:", unique_nums)
print("3이 있는가?:", 3 in unique_nums)
print("10이 있는가?:", 10 in unique_nums)
