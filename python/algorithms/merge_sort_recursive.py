"""병합 정렬 (재귀) 예시."""


def merge(left: list[int], right: list[int]) -> list[int]:
    i = j = 0
    merged: list[int] = []

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged


def merge_sort_recursive(arr: list[int]) -> list[int]:
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort_recursive(arr[:mid])
    right = merge_sort_recursive(arr[mid:])

    return merge(left, right)


if __name__ == "__main__":
    data = [5, 2, 9, 1, 3, 7]
    print(merge_sort_recursive(data))  # [1, 2, 3, 5, 7, 9]
