const word = 'algorithm';

console.log('원본:', word);
console.log('word.slice(1, 5) ->', word.slice(1, 5));
console.log('word.slice(0, 4) ->', word.slice(0, 4));
console.log('2칸씩 건너뛰기 ->', [...word].filter((_, i) => i % 2 === 0).join(''));
console.log('뒤집기 ->', [...word].reverse().join(''));
