/*
- 제목: 멤버십 조회 성능 비교
- 목적: 자료구조 선택이 성능에 미치는 영향을 체감합니다.
- 개념: 같은 질의를 vector 선형 검색과 unordered_set 검색으로 비교합니다.
- 시간복잡도(필요한 경우): vector: O(Q*N), unordered_set: 평균 O(N+Q)
- 핵심 변수 의미: n: 데이터 크기, qn: 질의 수, c1/c2: 포함된 질의 개수, t: 실행 시간
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 결과 개수(c1,c2)는 같아야 하며, 시간 비교로 set 조회의 장점을 학습합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

int contains_with_list(const std::vector<int>& data, const std::vector<int>& queries) {
    int count = 0;
    for (int q : queries) {
        if (std::find(data.begin(), data.end(), q) != data.end()) count++;
    }
    return count;
}

int contains_with_set(const std::vector<int>& data, const std::vector<int>& queries) {
    std::unordered_set<int> s(data.begin(), data.end());
    int count = 0;
    for (int q : queries) if (s.count(q)) count++;
    return count;
}

int main() {
    int n = 400000, qn = 200000;
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) data[i] = i;

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, n * 2);
    std::vector<int> queries(qn);
    for (int& x : queries) x = dist(rng);

    auto s1 = std::chrono::steady_clock::now();
    int c1 = contains_with_list(data, queries);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    int c2 = contains_with_set(data, queries);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "list 결과=" << c1 << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "set  결과=" << c2 << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
