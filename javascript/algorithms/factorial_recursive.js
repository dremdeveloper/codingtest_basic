function factorialRecursive(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');
  if (n <= 1) return 1;
  return n * factorialRecursive(n - 1);
}

console.log(factorialRecursive(5));
