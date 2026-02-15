"""14) Counter: 원소 빈도 계산."""
from collections import Counter

text = "banana"
counter = Counter(text)

print("문자열:", text)
print("빈도수 dict 형태:", dict(counter))
print("가장 많이 나온 문자 1개:", counter.most_common(1))
