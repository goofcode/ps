/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum2 = (candidates, target) => {
  const result = [];

  candidates.sort((a, b) => a - b);

  const find = (selected, target, idx) => {
    if (target === 0) {
      result.push(selected.slice());
      return;
    }
    if (target < 0 || idx >= candidates.length) {
      return;
    }

    const current = candidates[idx];
    let count = 0;
    while (idx + count < candidates.length && candidates[idx + count] === current) {
      count++;
    }

    for (let i = 0; i < count; i++) {
      selected.push(current);
      find(selected, target - current * (i + 1), idx + count);
    }
    selected.splice(selected.length - count, count);
    find(selected, target, idx + count);
  };

  find([], target, 0);

  return result;
};
