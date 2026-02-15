function factorialIterative(n) {
  if (n < 0) throw new Error('n은 0 이상이어야 합니다.');

  let result = 1;
  for (let i = 2; i <= n; i += 1) result *= i;
  return result;
}

console.log(factorialIterative(5));
