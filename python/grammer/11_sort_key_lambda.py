"""11) 정렬: key와 lambda로 기준 지정."""

students = [("kim", 70), ("lee", 90), ("park", 80)]

# 점수 기준 오름차순
by_score = sorted(students, key=lambda x: x[1])
# 이름 기준 내림차순
by_name_desc = sorted(students, key=lambda x: x[0], reverse=True)

print("원본:", students)
print("점수순:", by_score)
print("이름 내림차순:", by_name_desc)
