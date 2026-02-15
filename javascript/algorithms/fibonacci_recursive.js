function fibonacciRecursive(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');
  if (n <= 1) return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

console.log(fibonacciRecursive(10));
