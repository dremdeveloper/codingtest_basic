"""12) deque: 양쪽 끝 삽입/삭제가 빠른 큐."""
from collections import deque

q = deque([2, 3])
q.append(4)       # 오른쪽 추가
q.appendleft(1)   # 왼쪽 추가

print("추가 후:", list(q))
left = q.popleft()
right = q.pop()
print("왼쪽에서 꺼낸 값:", left)
print("오른쪽에서 꺼낸 값:", right)
print("최종 deque:", list(q))
