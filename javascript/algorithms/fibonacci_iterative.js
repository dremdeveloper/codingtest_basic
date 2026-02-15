function fibonacciIterative(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');
  if (n <= 1) return n;

  let a = 0;
  let b = 1;
  for (let i = 2; i <= n; i += 1) {
    [a, b] = [b, a + b];
  }
  return b;
}

console.log(fibonacciIterative(10));
