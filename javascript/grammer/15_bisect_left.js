function bisectLeft(arr, target) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < target) left = mid + 1;
    else right = mid;
  }
  return left;
}

function bisectRight(arr, target) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] <= target) left = mid + 1;
    else right = mid;
  }
  return left;
}

const arr = [1, 2, 2, 2, 5];
const target = 2;
const left = bisectLeft(arr, target);
const right = bisectRight(arr, target);

console.log('배열:', arr);
console.log('target의 왼쪽 경계:', left);
console.log('target 개수:', right - left);
