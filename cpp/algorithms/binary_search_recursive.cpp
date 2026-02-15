/*
- 제목: 이진 탐색(재귀)
- 목적: 반복문 없이 재귀 호출로 이진 탐색 사고를 훈련합니다.
- 개념: left~right 구간을 재귀적으로 반으로 나누며 target을 찾습니다.
- 시간복잡도(필요한 경우): O(log N) (N: 배열 길이)
- 핵심 변수 의미: left/right: 현재 탐색 구간, mid: 비교 기준 인덱스, target: 찾을 값
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 정답 인덱스/실패(-1)를 통해 재귀 종료 조건(left>right)의 의미를 확인할 수 있습니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <iostream>
#include <vector>

int binary_search_recursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binary_search_recursive(arr, target, mid + 1, right);
    return binary_search_recursive(arr, target, left, mid - 1);
}

int main() {
    std::vector<int> numbers{1,3,5,7,9,11,13};
    std::cout << "index: " << binary_search_recursive(numbers, 9, 0, numbers.size()-1) << "\n";
}
