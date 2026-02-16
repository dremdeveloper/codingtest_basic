/*
- 제목: 구간합 질의 성능 비교
- 목적: 전처리(prefix sum)의 효과를 시간으로 확인합니다.
- 개념: naive는 매 질의 합산, prefix는 전처리 후 O(1) 질의입니다.
- 시간복잡도(필요한 경우): naive: O(K*N), prefix: O(N+K)
- 핵심 변수 의미: n: 배열 크기, k: 질의 개수, queries: [l,r] 구간 목록, naive/fast: 결과 배열
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 첫 질의 결과값은 두 방식이 동일해야 하며 시간 차이로 알고리즘 선택 기준을 배웁니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<long long> range_sum_naive(const std::vector<int>& arr, const std::vector<std::pair<int,int>>& queries) {
    std::vector<long long> result;
    result.reserve(queries.size());
    for (auto [l, r] : queries) {
        long long sum = 0;
        for (int i = l; i <= r; ++i) sum += arr[i];
        result.push_back(sum);
    }
    return result;
}

std::vector<long long> build_prefix(const std::vector<int>& arr) {
    std::vector<long long> prefix(arr.size() + 1, 0);
    for (size_t i = 0; i < arr.size(); ++i) prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}

std::vector<long long> range_sum_prefix(const std::vector<long long>& prefix, const std::vector<std::pair<int,int>>& queries) {
    std::vector<long long> result;
    result.reserve(queries.size());
    for (auto [l, r] : queries) result.push_back(prefix[r + 1] - prefix[l]);
    return result;
}

int main() {
    int n = 200000, k = 100000;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> value_dist(1, 100);

    std::vector<int> arr(n);
    for (int& x : arr) x = value_dist(rng);

    std::vector<std::pair<int,int>> queries;
    queries.reserve(k);
    std::uniform_int_distribution<int> idx_dist(0, n - 1);
    for (int i = 0; i < k; ++i) {
        int a = idx_dist(rng), b = idx_dist(rng);
        if (a > b) std::swap(a, b);
        queries.push_back({a, b});
    }

    auto s1 = std::chrono::steady_clock::now();
    auto naive = range_sum_naive(arr, queries);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto prefix = build_prefix(arr);
    auto fast = range_sum_prefix(prefix, queries);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "naive 첫 결과=" << naive[0] << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "prefix 첫 결과=" << fast[0] << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
