"""퀵 정렬 (반복, 스택) 예시."""


def partition(arr: list[int], low: int, high: int) -> int:
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quicksort_iterative(arr: list[int]) -> list[int]:
    result = arr[:]
    stack = [(0, len(result) - 1)]

    while stack:
        low, high = stack.pop()
        if low >= high:
            continue

        p = partition(result, low, high)

        stack.append((low, p - 1))
        stack.append((p + 1, high))

    return result


if __name__ == "__main__":
    data = [8, 4, 7, 3, 9, 2, 6, 5]
    print(quicksort_iterative(data))  # [2, 3, 4, 5, 6, 7, 8, 9]
