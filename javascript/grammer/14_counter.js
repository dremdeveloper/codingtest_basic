const text = 'banana';
const counter = {};

for (const ch of text) counter[ch] = (counter[ch] ?? 0) + 1;
const top1 = Object.entries(counter).sort((a, b) => b[1] - a[1])[0];

console.log('문자열:', text);
console.log('빈도수 객체:', counter);
console.log('가장 많이 나온 문자 1개:', top1);
