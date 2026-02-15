"""13) heapq: 최소 힙으로 우선순위 큐 구현."""
import heapq

numbers = [5, 1, 4, 2]
heap = []

for n in numbers:
    heapq.heappush(heap, n)
    print("push", n, "->", heap)

smallest = heapq.heappop(heap)
print("가장 작은 값 pop:", smallest)
print("남은 힙:", heap)
