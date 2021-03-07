/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = (candidates, target) => {
  const result = [];

  const find = (selected, sum, idx) => {
    if (sum === target) {
      result.push(selected.slice());
      return;
    }

    if (sum > target || idx >= candidates.length) {
      return;
    }

    const current = candidates[idx];
    selected.push(current);
    find(selected, sum + current, idx); // select current
    selected.pop();
    find(selected, sum, idx + 1); // pass current
  };

  find([], 0, 0);

  return result;
};

combinationSum([2, 3, 6, 7], 7);
