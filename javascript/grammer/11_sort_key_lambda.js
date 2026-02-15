const students = [['kim', 70], ['lee', 90], ['park', 80]];

const byScore = [...students].sort((a, b) => a[1] - b[1]);
const byNameDesc = [...students].sort((a, b) => (a[0] < b[0] ? 1 : -1));

console.log('원본:', students);
console.log('점수순:', byScore);
console.log('이름 내림차순:', byNameDesc);
