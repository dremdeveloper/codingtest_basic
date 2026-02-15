/*
- 제목: LIS(이분 탐색 최적화)
- 목적: 최장 증가 부분수열 길이를 O(N log N)으로 구하는 방법을 학습합니다.
- 개념: tails[k]=길이 k+1 수열의 최소 끝값을 유지합니다.
- 시간복잡도(필요한 경우): O(N log N)
- 핵심 변수 의미: arr: 입력 수열, tails: 길이별 최소 끝값 배열, it: lower_bound 위치
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력 4는 예제 수열의 LIS 길이가 4임을 의미합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int lis_dp_binary_search(const std::vector<int>& arr) {
    std::vector<int> tails;
    for (int x : arr) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

int main() {
    std::vector<int> arr{10,20,10,30,20,50};
    std::cout << lis_dp_binary_search(arr) << '\n';
}
