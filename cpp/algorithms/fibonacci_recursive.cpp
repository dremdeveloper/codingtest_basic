/*
- 제목: 피보나치(재귀)
- 목적: 점화식 기반 재귀 호출 트리의 구조를 학습합니다.
- 개념: F(n)=F(n-1)+F(n-2) 점화식을 그대로 구현합니다.
- 시간복잡도(필요한 경우): O(2^N)
- 핵심 변수 의미: n: 구하려는 항 번호
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명(학습 포인트): 55(F(10))를 통해 점화식이 올바르게 적용되는지 확인합니다. 또한 이 출력이 왜 나오는지(입력 데이터와 알고리즘/문법 규칙의 대응 관계)를 역으로 설명해보면 학습 효과가 크게 올라갑니다. 가능하면 출력값이 바뀌도록 입력을 직접 수정해 보고, 어떤 규칙 때문에 결과가 달라졌는지 비교해 보세요. [학습 확장] (1) 먼저 현재 입력 기준으로 왜 이 결과가 나오는지 각 변수의 값 변화(예: 인덱스 이동, 누적값 변화, 자료구조 상태 변화)로 추적해 보세요. (2) 같은 로직에서 입력 크기/값 분포를 바꿨을 때 결과와 실행시간이 어떻게 달라지는지 비교하면 시간복잡도 감각을 함께 얻을 수 있습니다. (3) 출력 결과가 정답 조건을 어떻게 만족하는지(예: 정렬 여부, 최단거리 조건, 중복 제거 결과 일치)를 체크리스트로 검증해 보세요.
*/

#include <iostream>
#include <stdexcept>

long long fibonacci_recursive(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    std::cout << fibonacci_recursive(10) << '\n'; }
