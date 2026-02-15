"""퀵 정렬 (재귀) 예시."""


def quicksort_recursive(arr: list[int]) -> list[int]:
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quicksort_recursive(left) + middle + quicksort_recursive(right)


if __name__ == "__main__":
    data = [8, 4, 7, 3, 9, 2, 6, 5]
    print(quicksort_recursive(data))  # [2, 3, 4, 5, 6, 7, 8, 9]
