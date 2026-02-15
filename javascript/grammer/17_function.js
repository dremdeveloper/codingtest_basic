function gcd(a, b) {
  while (b !== 0) [a, b] = [b, a % b];
  return a;
}

const x = 12;
const y = 18;
console.log(`gcd(${x}, ${y}) =`, gcd(x, y));
