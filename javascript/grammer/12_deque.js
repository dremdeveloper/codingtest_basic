const q = [2, 3];
q.push(4);
q.unshift(1);

console.log('추가 후:', q);
const left = q.shift();
const right = q.pop();
console.log('왼쪽에서 꺼낸 값:', left);
console.log('오른쪽에서 꺼낸 값:', right);
console.log('최종 덱 유사 배열:', q);
