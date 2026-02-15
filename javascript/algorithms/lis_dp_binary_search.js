function bisectLeft(arr, x) {
  let left = 0;
  let right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

function lisLength(arr) {
  const tails = [];

  for (const x of arr) {
    const idx = bisectLeft(tails, x);
    if (idx === tails.length) tails.push(x);
    else tails[idx] = x;
  }

  return tails.length;
}

console.log(lisLength([10, 20, 10, 30, 20, 50]));
