function binarySearchRecursive(arr, target, left, right) {
  if (left > right) return -1;

  const mid = Math.floor((left + right) / 2);
  if (arr[mid] === target) return mid;
  if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, right);
  return binarySearchRecursive(arr, target, left, mid - 1);
}

const numbers = [1, 3, 5, 7, 9, 11, 13];
console.log(`index: ${binarySearchRecursive(numbers, 9, 0, numbers.length - 1)}`);
