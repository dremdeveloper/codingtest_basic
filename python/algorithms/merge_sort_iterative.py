"""병합 정렬 (반복, Bottom-Up) 예시."""


def merge_sections(arr: list[int], left: int, mid: int, right: int) -> None:
    left_part = arr[left:mid]
    right_part = arr[mid:right]

    i = j = 0
    k = left

    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1


def merge_sort_iterative(arr: list[int]) -> list[int]:
    n = len(arr)
    size = 1
    result = arr[:]

    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(left + size, n)
            right = min(left + 2 * size, n)
            merge_sections(result, left, mid, right)
        size *= 2

    return result


if __name__ == "__main__":
    data = [5, 2, 9, 1, 3, 7]
    print(merge_sort_iterative(data))  # [1, 2, 3, 5, 7, 9]
