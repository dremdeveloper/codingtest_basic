# 코딩 테스트 대비 기본 알고리즘 예시 (Python)

코딩 테스트에서 자주 등장하는 기본 알고리즘 예시를 모아두었습니다.

재귀/비재귀(반복) 구현이 모두 가능한 알고리즘은 각각 분리해 두었습니다.
또한 각 예제 파일에 **친절한 설명 주석**을 넣어, 처음 보는 분도 흐름을 따라가기 쉽게 구성했습니다.

## 파일 목록

### 탐색 / 그래프
- `binary_search_recursive.py`: 이진 탐색 (재귀)
- `binary_search_iterative.py`: 이진 탐색 (반복)
- `dfs_recursive.py`: DFS (재귀)
- `dfs_iterative.py`: DFS (반복, 스택)
- `bfs_queue.py`: BFS (큐)
- `dijkstra_heap.py`: 다익스트라 최단 경로 (우선순위 큐)
- `topological_sort_kahn.py`: 위상 정렬 (Kahn)
- `union_find.py`: 유니온 파인드(함수형, class 미사용)

### 정렬
- `merge_sort_recursive.py`: 병합 정렬 (재귀)
- `merge_sort_iterative.py`: 병합 정렬 (반복, Bottom-Up)
- `quicksort_recursive.py`: 퀵 정렬 (재귀)
- `quicksort_iterative.py`: 퀵 정렬 (반복, 스택)

### 수학 / 분할정복
- `factorial_recursive.py`: 팩토리얼 (재귀)
- `factorial_iterative.py`: 팩토리얼 (반복)
- `fibonacci_recursive.py`: 피보나치 수열 (재귀)
- `fibonacci_iterative.py`: 피보나치 수열 (반복)
- `gcd_recursive.py`: 최대공약수 (재귀)
- `gcd_iterative.py`: 최대공약수 (반복)
- `power_recursive.py`: 거듭제곱 (재귀, 분할 정복)
- `power_iterative.py`: 거듭제곱 (반복, 이진 지수법)

### 동적 계획법
- `knapsack_01_dp.py`: 0/1 배낭 문제
- `lis_dp_binary_search.py`: 최장 증가 부분 수열 (LIS, O(n log n))

총 22개 예시 파일을 포함합니다.

각 파일은 바로 실행 가능한 간단한 예제(`if __name__ == "__main__":`)를 포함합니다.
