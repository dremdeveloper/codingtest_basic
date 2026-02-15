function powerRecursive(base, exp) {
  if (exp < 0) throw new Error('exp는 0 이상이어야 합니다.');
  if (exp === 0) return 1;
  if (exp === 1) return base;

  const half = powerRecursive(base, Math.floor(exp / 2));
  if (exp % 2 === 0) return half * half;
  return half * half * base;
}

console.log(powerRecursive(2, 10));
