/*
- 제목: 유니온 파인드 (Disjoint Set)
- 개념: 서로소 집합을 관리해 연결 여부를 빠르게 판단합니다.
- 시간복잡도(필요한 경우): 거의 O(1) (경로압축+랭크)
- 주요 변수 의미: parent: 각 원소의 부모, rank: 트리 높이 근사, find: 대표자 탐색, union: 집합 합치기
- 실행 흐름: find는 경로압축으로 parent를 루트로 갱신하고, union은 rank 낮은 트리를 높은 트리에 붙입니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function makeSets(size) {
  const parent = Array.from({ length: size }, (_, i) => i);
  const rank = Array(size).fill(0);
  return [parent, rank];
}

function find(parent, x) {
  if (parent[x] !== x) parent[x] = find(parent, parent[x]);
  return parent[x];
}

function union(parent, rank, a, b) {
  const rootA = find(parent, a);
  const rootB = find(parent, b);

  if (rootA === rootB) return false;

  if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
  else if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
  else {
    parent[rootB] = rootA;
    rank[rootA] += 1;
  }

  return true;
}

const [parentData, rankData] = makeSets(7);
union(parentData, rankData, 1, 2);
union(parentData, rankData, 2, 3);
union(parentData, rankData, 4, 5);
console.log(find(parentData, 1) === find(parentData, 3));
console.log(find(parentData, 1) === find(parentData, 5));
