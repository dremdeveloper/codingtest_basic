function gcdRecursive(a, b) {
  a = Math.abs(a);
  b = Math.abs(b);
  if (b === 0) return a;
  return gcdRecursive(b, a % b);
}

console.log(gcdRecursive(48, 18));
