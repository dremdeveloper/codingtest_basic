/*
- 제목: 0/1 배낭 DP
- 목적: "선택/미선택" 최적화 문제를 1차원 DP로 푸는 법을 학습합니다.
- 개념: 각 물건마다 용량을 역순 갱신해 물건 중복 선택을 방지합니다.
- 시간복잡도(필요한 경우): O(N*W) (N: 물건 수, W: 최대 용량)
- 핵심 변수 의미: w[i]/v[i]: i번 물건의 무게/가치, cap: 배낭 용량, dp[c]: 용량 c 최대 가치
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 예제에서 37이 출력되며, 제한 용량 안에서 얻을 수 있는 최댓값 의미입니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <iostream>
#include <vector>

int knapsack_01_dp(const std::vector<int>& w, const std::vector<int>& v, int cap) {
    std::vector<int> dp(cap + 1, 0);
    for (size_t i = 0; i < w.size(); ++i) {
        for (int c = cap; c >= w[i]; --c) {
            dp[c] = std::max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    return dp[cap];
}

int main() {
    std::vector<int> w{2,1,3,2}, v{12,10,20,15};
    std::cout << knapsack_01_dp(w, v, 5) << '\n';
}
