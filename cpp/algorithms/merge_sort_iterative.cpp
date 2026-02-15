/*
- 제목: 병합 정렬(반복)
- 목적: 재귀 없이 Bottom-Up 방식으로 병합 정렬을 구현하는 법을 학습합니다.
- 개념: width를 1,2,4...로 키우며 인접 구간을 반복 병합합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 핵심 변수 의미: width: 현재 부분배열 크기, l/m/r: 병합 대상 구간 경계, tmp: 임시 버퍼
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 결과가 오름차순이 되며, 재귀 없이도 같은 정렬 결과를 얻음을 배웁니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void merge_sort_iterative(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> tmp(n);
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int l = i;
            int m = std::min(i + width, n);
            int r = std::min(i + 2 * width, n);
            int p = l, q = m, t = l;
            while (p < m && q < r) tmp[t++] = (arr[p] <= arr[q]) ? arr[p++] : arr[q++];
            while (p < m) tmp[t++] = arr[p++];
            while (q < r) tmp[t++] = arr[q++];
            for (int k = l; k < r; ++k) arr[k] = tmp[k];
        }
    }
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    merge_sort_iterative(arr);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
