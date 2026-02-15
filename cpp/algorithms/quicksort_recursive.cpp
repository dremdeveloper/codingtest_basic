/*
- 제목: 퀵 정렬(재귀)
- 목적: 분할 기준(pivot)을 이용한 제자리 정렬 아이디어를 학습합니다.
- 개념: partition으로 pivot 위치를 확정하고 좌/우 구간을 재귀 정렬합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 핵심 변수 의미: pivot: 분할 기준 값, l/r: 정렬 구간 경계, p: pivot 최종 위치
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 정렬 결과와 pivot 분할 원리를 함께 이해할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) {
        if (arr[j] <= pivot) std::swap(arr[i++], arr[j]);
    }
    std::swap(arr[i], arr[r]);
    return i;
}

void quicksort_recursive(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quicksort_recursive(arr, l, p - 1);
    quicksort_recursive(arr, p + 1, r);
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    quicksort_recursive(arr, 0, arr.size()-1);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
