"""9) 반복문(for): range와 누적합 패턴."""

total = 0
for i in range(1, 6):  # 1~5
    total += i
    print(f"i={i}, 현재 누적합={total}")

print("최종 합계:", total)
