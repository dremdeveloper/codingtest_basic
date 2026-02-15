function quicksortRecursive(arr) {
  if (arr.length <= 1) return arr;

  const pivot = arr[Math.floor(arr.length / 2)];
  const left = arr.filter((x) => x < pivot);
  const middle = arr.filter((x) => x === pivot);
  const right = arr.filter((x) => x > pivot);

  return [...quicksortRecursive(left), ...middle, ...quicksortRecursive(right)];
}

console.log(quicksortRecursive([8, 4, 7, 3, 9, 2, 6, 5]));
