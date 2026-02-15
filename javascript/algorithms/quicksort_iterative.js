/*
- 제목: 퀵 정렬 (반복, 스택)
- 개념: 재귀 대신 스택으로 정렬할 구간을 관리합니다.
- 시간복잡도(필요한 경우): 평균 O(N log N), 최악 O(N^2)
- 주요 변수 의미: stack: 처리할 [low,high] 구간 목록, p: partition 결과 pivot 위치
- 실행 흐름: 구간을 꺼내 partition 후 좌/우 하위 구간을 stack에 push합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

function partition(arr, low, high) {
  const pivot = arr[high];
  let i = low - 1;

  for (let j = low; j < high; j += 1) {
    if (arr[j] <= pivot) {
      i += 1;
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }

  [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
  return i + 1;
}

function quicksortIterative(arr) {
  const result = [...arr];
  const stack = [[0, result.length - 1]];

  while (stack.length) {
    const [low, high] = stack.pop();
    if (low >= high) continue;

    const p = partition(result, low, high);
    stack.push([low, p - 1]);
    stack.push([p + 1, high]);
  }

  return result;
}

console.log(quicksortIterative([8, 4, 7, 3, 9, 2, 6, 5]));
