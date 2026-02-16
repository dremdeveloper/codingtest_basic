/*
- 제목: 문자열 빌드 성능 비교
- 목적: 문자열 결합 방식 차이에 따른 성능 변화를 학습합니다.
- 개념: 단순 += 반복과 reserve 후 누적 결합을 비교합니다.
- 시간복잡도(필요한 경우): 총 길이 L 기준 둘 다 O(L)이나 재할당 비용 차이 존재
- 핵심 변수 의미: chunks: 결합할 문자열 조각, a/b: 두 방식 결과 문자열, t1/t2: 실행 시간
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 길이는 같고 시간은 보통 reserve 방식이 더 안정적으로 빠릅니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

std::string build_with_plus(const std::vector<std::string>& chunks) {
    std::string result;
    for (const auto& ch : chunks) result += ch;
    return result;
}

std::string build_with_reserve(const std::vector<std::string>& chunks) {
    size_t total = 0;
    for (const auto& ch : chunks) total += ch.size();
    std::string result;
    result.reserve(total);
    for (const auto& ch : chunks) result += ch;
    return result;
}

int main() {
    std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<std::string> chunks;
    chunks.reserve(letters.size() * 80000);
    for (int i = 0; i < 80000; ++i) for (char c : letters) chunks.emplace_back(1, c);

    auto s1 = std::chrono::steady_clock::now();
    auto a = build_with_plus(chunks);
    auto e1 = std::chrono::steady_clock::now();

    auto s2 = std::chrono::steady_clock::now();
    auto b = build_with_reserve(chunks);
    auto e2 = std::chrono::steady_clock::now();

    std::cout << "+= 길이=" << a.size() << ", 시간=" << std::chrono::duration<double>(e1-s1).count() << "s\n";
    std::cout << "reserve 길이=" << b.size() << ", 시간=" << std::chrono::duration<double>(e2-s2).count() << "s\n";
}
