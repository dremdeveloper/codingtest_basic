/*
- 제목: 중복 제거 성능 비교
- 목적: 중복 제거에서 해시 기반 보조구조의 장점을 학습합니다.
- 개념: 결과 벡터 선형 탐색 방식과 unordered_set 보조 방식을 비교합니다.
- 시간복잡도(필요한 경우): naive: O(N^2), set 보조: 평균 O(N)
- 핵심 변수 의미: nums: 원본 데이터, result: 중복 제거 결과, seen: 이미 본 값 집합
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 고유 개수는 두 방식이 같아야 하며 시간 차이로 최적 자료구조를 이해합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <chrono>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

std::vector<int> dedup_naive(const std::vector<int>& nums) {
    std::vector<int> result;
    for (int x : nums) {
        bool exists = false;
        for (int y : result) {
            if (y == x) { exists = true; break; }
        }
        if (!exists) result.push_back(x);
    }
    return result;
}

std::vector<int> dedup_with_set(const std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (!seen.count(x)) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    int n = 300000;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 30000);
    std::vector<int> nums(n);
    for (int& x : nums) x = dist(rng);

    auto s1 = std::chrono::steady_clock::now();
    auto a = dedup_naive(nums);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto b = dedup_with_set(nums);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "naive 고유개수=" << a.size() << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "set   고유개수=" << b.size() << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
