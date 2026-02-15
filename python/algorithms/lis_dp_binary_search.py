"""최장 증가 부분 수열(LIS, O(n log n)) 예시."""

from bisect import bisect_left


def lis_length(arr: list[int]) -> int:
    # tails[k] = 길이가 k+1인 증가 부분 수열의 마지막 값 중 최소값
    tails: list[int] = []

    for x in arr:
        # x가 들어갈 가장 왼쪽 위치를 찾아 tails를 갱신
        idx = bisect_left(tails, x)
        if idx == len(tails):
            tails.append(x)
        else:
            tails[idx] = x

    return len(tails)


if __name__ == "__main__":
    data = [10, 20, 10, 30, 20, 50]
    print(lis_length(data))  # 4
