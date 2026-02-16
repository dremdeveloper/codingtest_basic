/*
- 제목: 병합 정렬(재귀)
- 목적: 분할 정복 정렬의 대표 패턴을 이해합니다.
- 개념: 배열을 반으로 나누어 정렬 후 merge로 결합합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 핵심 변수 의미: l/r: 현재 구간 양끝, m: 중간 인덱스, tmp: 병합 임시 배열
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 정렬 전후를 비교해 "분할→정복→병합" 구조를 학습할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) tmp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    while (i <= m) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = 0; k < (int)tmp.size(); ++k) arr[l + k] = tmp[k];
}

void merge_sort_recursive(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort_recursive(arr, l, m);
    merge_sort_recursive(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    std::vector<int> arr{5,2,4,6,1,3};
    merge_sort_recursive(arr, 0, arr.size()-1);
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
