const arr = [3, 1, 2];
console.log('초기 배열:', arr);

arr.push(4);
arr.splice(arr.indexOf(1), 1);
arr.sort((x, y) => x - y);

console.log('변경 후 배열:', arr);
console.log('첫 번째 원소:', arr[0], '마지막 원소:', arr[arr.length - 1]);
