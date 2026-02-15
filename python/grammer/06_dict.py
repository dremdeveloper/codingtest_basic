"""6) 딕셔너리: key-value 조회/추가/갱신."""

score = {"A": 100, "B": 80}
print("초기 dict:", score)

score["C"] = 95          # 새 키 추가
score["B"] = 85          # 기존 값 갱신

print("A 점수 조회:", score["A"])
print("모든 키:", list(score.keys()))
print("최종 dict:", score)
