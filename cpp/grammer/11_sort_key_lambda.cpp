/*
- 제목: C++ 문법 기본 예제
- 목적: Python에서 자주 쓰는 문법 개념을 C++로 대응해 이해합니다.
- 개념: 표준 라이브러리 자료구조/문법을 작은 예제로 확인합니다.
- 시간복잡도(필요한 경우): 해당 없음(학습용 문법 예제)
- 핵심 변수 의미: 파일마다 선언된 변수는 예시 입력/출력 시나리오를 보여주기 위한 샘플 데이터입니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 출력값을 통해 해당 문법 기능이 실제로 어떻게 동작하는지 직접 확인하는 것이 목표입니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::pair<std::string, int>> students{{"kim",70},{"lee",90},{"park",80}};

    auto by_score = students;
    std::sort(by_score.begin(), by_score.end(), [](auto& a, auto& b){ return a.second < b.second; });

    auto by_name_desc = students;
    std::sort(by_name_desc.begin(), by_name_desc.end(), [](auto& a, auto& b){ return a.first > b.first; });

    std::cout << "점수순: ";
    for (auto& [n,s] : by_score) std::cout << '(' << n << ',' << s << ") ";
    std::cout << "\n이름 내림차순: ";
    for (auto& [n,s] : by_name_desc) std::cout << '(' << n << ',' << s << ") ";
    std::cout << '\n';
}
