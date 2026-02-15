"""8) 조건문: if / elif / else 기본 형태."""

score = 82

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
else:
    grade = "C"

print("점수:", score)
print("등급:", grade)
