"""4) 리스트: 추가/삭제/정렬 같은 기본 조작."""

arr = [3, 1, 2]
print("초기 리스트:", arr)

arr.append(4)        # 맨 뒤 추가
arr.remove(1)        # 값 1 제거
arr.sort()           # 오름차순 정렬

print("변경 후 리스트:", arr)
print("첫 번째 원소:", arr[0], "마지막 원소:", arr[-1])
