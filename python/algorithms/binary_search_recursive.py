"""이진 탐색 (재귀) 예시."""


def binary_search_recursive(arr: list[int], target: int, left: int, right: int) -> int:
    if left > right:
        return -1

    mid = (left + right) // 2

    if arr[mid] == target:
        return mid
    if arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    return binary_search_recursive(arr, target, left, mid - 1)


if __name__ == "__main__":
    numbers = [1, 3, 5, 7, 9, 11, 13]
    idx = binary_search_recursive(numbers, 9, 0, len(numbers) - 1)
    print(f"index: {idx}")  # 4
