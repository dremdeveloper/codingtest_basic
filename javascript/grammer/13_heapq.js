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
