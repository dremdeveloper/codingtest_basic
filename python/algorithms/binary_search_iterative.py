"""이진 탐색 (반복) 예시."""


def binary_search_iterative(arr: list[int], target: int) -> int:
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


if __name__ == "__main__":
    numbers = [1, 3, 5, 7, 9, 11, 13]
    idx = binary_search_iterative(numbers, 7)
    print(f"index: {idx}")  # 3
