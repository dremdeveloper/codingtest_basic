let total = 0;
for (let i = 1; i <= 5; i += 1) {
  total += i;
  console.log(`i=${i}, 현재 누적합=${total}`);
}
console.log('최종 합계:', total);
