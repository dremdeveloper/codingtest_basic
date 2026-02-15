/*
- 제목: 최소 힙
- 개념: 우선순위 큐 핵심 연산
- 시간복잡도(필요한 경우): push/pop O(log N)
- 주요 변수 의미: h: 힙 배열, push/pop: 핵심 연산
- 실행 흐름: push 시 상향, pop 시 하향 정렬로 힙 성질을 유지합니다. 또한 입력 준비 → 핵심 함수 호출 → 출력 검증의 3단계로 코드를 읽으면서, 각 단계에서 어떤 변수가 갱신되고 왜 그런 값이 되는지 추적하면 학습 효과가 크게 높아집니다. 특히 출력을 보기 전에 먼저 예상값을 손으로 계산해 본 뒤 실제 결과와 비교해보면 개념이 훨씬 오래 기억됩니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
*/

class MinHeap {
  constructor() { this.h = []; }
  push(x) {
    this.h.push(x);
    let i = this.h.length - 1;
    while (i > 0) {
      const p = Math.floor((i - 1) / 2);
      if (this.h[p] <= this.h[i]) break;
      [this.h[p], this.h[i]] = [this.h[i], this.h[p]];
      i = p;
    }
  }
  pop() {
    if (!this.h.length) return undefined;
    const top = this.h[0];
    const end = this.h.pop();
    if (this.h.length) {
      this.h[0] = end;
      let i = 0;
      while (true) {
        let s = i;
        const l = i * 2 + 1;
        const r = i * 2 + 2;
        if (l < this.h.length && this.h[l] < this.h[s]) s = l;
        if (r < this.h.length && this.h[r] < this.h[s]) s = r;
        if (s === i) break;
        [this.h[i], this.h[s]] = [this.h[s], this.h[i]];
        i = s;
      }
    }
    return top;
  }
}

const numbers = [5, 1, 4, 2];
const heap = new MinHeap();
for (const n of numbers) {
  heap.push(n);
  console.log('push', n, '->', heap.h);
}
console.log('가장 작은 값 pop:', heap.pop());
console.log('남은 힙:', heap.h);
