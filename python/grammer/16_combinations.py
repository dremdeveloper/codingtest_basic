"""16) combinations: 순서 없이 r개 선택."""
from itertools import combinations

items = ["A", "B", "C", "D"]
result = list(combinations(items, 2))

print("원소:", items)
print("2개 조합:", result)
print("조합 개수:", len(result))
