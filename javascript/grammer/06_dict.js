const score = { A: 100, B: 80 };
console.log('초기 객체:', score);

score.C = 95;
score.B = 85;

console.log('A 점수 조회:', score.A);
console.log('모든 키:', Object.keys(score));
console.log('최종 객체:', score);
