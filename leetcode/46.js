/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const permuteUnique = (nums) => {
  const result = [];
  const perm = (selected, left) => {
    if (left.length === 0) {
      result.push([...selected]);
      return;
    }

    const contained = new Set();
    for (let i = 0; i < left.length; i++) {
      const cur = left[i];
      if (contained.has(cur)) {
        continue;
      }

      contained.add(cur);
      selected.push(cur);
      left.splice(i, 1);
      perm(selected, left);
      selected.pop();
      left.splice(i, 0, cur);
    }
  };

  perm([], nums);
  return result;
};
