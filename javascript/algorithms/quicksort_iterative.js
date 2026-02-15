function partition(arr, low, high) {
  const pivot = arr[high];
  let i = low - 1;

  for (let j = low; j < high; j += 1) {
    if (arr[j] <= pivot) {
      i += 1;
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }

  [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
  return i + 1;
}

function quicksortIterative(arr) {
  const result = [...arr];
  const stack = [[0, result.length - 1]];

  while (stack.length) {
    const [low, high] = stack.pop();
    if (low >= high) continue;

    const p = partition(result, low, high);
    stack.push([low, p - 1]);
    stack.push([p + 1, high]);
  }

  return result;
}

console.log(quicksortIterative([8, 4, 7, 3, 9, 2, 6, 5]));
