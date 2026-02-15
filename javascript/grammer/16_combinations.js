function combinations(items, r) {
  const result = [];
  const path = [];

  function backtrack(start) {
    if (path.length === r) {
      result.push([...path]);
      return;
    }
    for (let i = start; i < items.length; i += 1) {
      path.push(items[i]);
      backtrack(i + 1);
      path.pop();
    }
  }

  backtrack(0);
  return result;
}

const items = ['A', 'B', 'C', 'D'];
const result = combinations(items, 2);
console.log('원소:', items);
console.log('2개 조합:', result);
console.log('조합 개수:', result.length);
