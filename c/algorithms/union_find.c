/*
- 제목: 유니온 파인드
- 개념: 서로소 집합 자료구조로 합치기(union)와 대표 찾기(find)를 빠르게 수행합니다.
- 시간복잡도(필요한 경우): 거의 O(1) (경로 압축 시, 정확히는 역아커만)
- 주요 변수 의미: parent[x]: x의 부모(대표), find: 대표 탐색/압축, unite: 두 집합 병합
- 실행 흐름 요약:
  1) parent[i]=i로 각 원소를 독립 집합으로 초기화합니다.
  2) unite(a,b) 호출 시 find로 각 대표를 찾고 대표를 연결합니다.
  3) find는 경로 압축으로 이후 탐색을 빠르게 만듭니다.
  4) 두 원소의 대표가 같으면 같은 집합으로 판단합니다.
  5) 출력 YES/NO로 집합 병합 결과를 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 1과 3이 연결되어 YES가 출력됩니다.
*/

#include <stdio.h>

int parent[10];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a,int b){
    a=find(a); b=find(b);
    if(a!=b) parent[b]=a;
}

int main(void){
    for(int i=0;i<10;i++) parent[i]=i;
    unite(1,2); unite(2,3);
    printf("1과 3 같은 집합? %s\n", find(1)==find(3)?"YES":"NO");
    return 0;
}
