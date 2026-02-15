function powerIterative(base, exp) {
  if (exp < 0) throw new Error('exp는 0 이상이어야 합니다.');

  let result = 1;
  let x = base;
  let n = exp;

  while (n > 0) {
    if (n & 1) result *= x;
    x *= x;
    n >>= 1;
  }

  return result;
}

console.log(powerIterative(2, 10));
