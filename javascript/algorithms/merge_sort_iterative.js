function mergeSections(arr, left, mid, right) {
  const leftPart = arr.slice(left, mid);
  const rightPart = arr.slice(mid, right);
  let i = 0;
  let j = 0;
  let k = left;

  while (i < leftPart.length && j < rightPart.length) {
    if (leftPart[i] <= rightPart[j]) arr[k++] = leftPart[i++];
    else arr[k++] = rightPart[j++];
  }

  while (i < leftPart.length) arr[k++] = leftPart[i++];
  while (j < rightPart.length) arr[k++] = rightPart[j++];
}

function mergeSortIterative(arr) {
  const result = [...arr];
  const n = result.length;
  let size = 1;

  while (size < n) {
    for (let left = 0; left < n; left += size * 2) {
      const mid = Math.min(left + size, n);
      const right = Math.min(left + size * 2, n);
      mergeSections(result, left, mid, right);
    }
    size *= 2;
  }

  return result;
}

console.log(mergeSortIterative([5, 2, 9, 1, 3, 7]));
