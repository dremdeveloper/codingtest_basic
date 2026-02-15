"""3) 문자열 슬라이싱: 시작/끝/간격 사용법."""

word = "algorithm"

print("원본:", word)
print("word[1:5] ->", word[1:5])      # 1번부터 4번 인덱스까지
print("word[:4]  ->", word[:4])       # 처음부터 3번 인덱스까지
print("word[::2] ->", word[::2])      # 2칸씩 건너뛰기
print("word[::-1] ->", word[::-1])    # 뒤집기
