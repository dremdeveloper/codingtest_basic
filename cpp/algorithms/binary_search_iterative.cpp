/*
- 제목: 이진 탐색(반복)
- 목적: 정렬된 배열에서 원하는 값을 빠르게 찾는 방법을 익힙니다.
- 개념: 중앙값(mid)과 target을 비교해 탐색 범위를 절반씩 줄입니다.
- 시간복잡도(필요한 경우): O(log N) (N: 배열 길이)
- 핵심 변수 의미: left/right: 현재 탐색 구간의 양끝 인덱스, mid: 가운데 인덱스, target: 찾을 값
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 인덱스가 곧 target 위치입니다. -1이면 배열에 값이 없다는 의미입니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <iostream>
#include <vector>

int binary_search_iterative(const std::vector<int>& arr, int target) {
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> numbers{1,3,5,7,9,11,13};
    std::cout << "index: " << binary_search_iterative(numbers, 7) << "\n";
}
