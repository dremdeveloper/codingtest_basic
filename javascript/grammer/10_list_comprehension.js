const evenSquares = Array.from({ length: 10 }, (_, i) => i + 1)
  .filter((x) => x % 2 === 0)
  .map((x) => x * x);

console.log('짝수 제곱 배열:', evenSquares);
console.log('원소 개수:', evenSquares.length);
