const nums = [1, 1, 2, 3, 3, 4];
const uniqueNums = new Set(nums);

console.log('원본 배열:', nums);
console.log('중복 제거 결과:', [...uniqueNums]);
console.log('3이 있는가?:', uniqueNums.has(3));
console.log('10이 있는가?:', uniqueNums.has(10));
