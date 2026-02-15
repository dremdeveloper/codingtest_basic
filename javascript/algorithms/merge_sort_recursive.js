function merge(left, right) {
  const merged = [];
  let i = 0;
  let j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) merged.push(left[i++]);
    else merged.push(right[j++]);
  }

  return [...merged, ...left.slice(i), ...right.slice(j)];
}

function mergeSortRecursive(arr) {
  if (arr.length <= 1) return arr;
  const mid = Math.floor(arr.length / 2);
  return merge(mergeSortRecursive(arr.slice(0, mid)), mergeSortRecursive(arr.slice(mid)));
}

console.log(mergeSortRecursive([5, 2, 9, 1, 3, 7]));
