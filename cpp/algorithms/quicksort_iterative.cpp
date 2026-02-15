/*
- 제목: 퀵 정렬(반복)
- 목적: 재귀 퀵정렬을 스택으로 변환하는 방법을 학습합니다.
- 개념: 정렬할 구간(l,r)을 스택에 저장해 반복 처리합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 핵심 변수 의미: st: 정렬할 구간 스택, p: partition 결과 인덱스
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 오름차순 결과로 반복 구현의 정확성을 확인할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <stack>
#include <vector>

int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) if (arr[j] <= pivot) std::swap(arr[i++], arr[j]);
    std::swap(arr[i], arr[r]);
    return i;
}

void quicksort_iterative(std::vector<int>& arr) {
    std::stack<std::pair<int,int>> st;
    st.push({0, (int)arr.size()-1});
    while (!st.empty()) {
        auto [l, r] = st.top(); st.pop();
        if (l >= r) continue;
        int p = partition(arr, l, r);
        st.push({l, p - 1});
        st.push({p + 1, r});
    }
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    quicksort_iterative(arr);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
