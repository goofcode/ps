/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const nextPermutation = (nums) => {
  const n = nums.length;
  let base = nums.length - 2;
  while (nums[base] >= nums[base + 1]) {
    base--;
  }

  // last perm
  if (base === -1) {
    return nums.reverse();
  }

  // find next start
  let nextIdx = base + 1;
  for (let i = base + 2; i < n; i++) {
    if (nums[i] > nums[base] && nums[i] <= nums[nextIdx]) {
      nextIdx = i;
    }
  }

  const swap = (i, j) => {
    [nums[i], nums[j]] = [nums[j], nums[i]];
  };

  swap(base, nextIdx);

  for (let i = base + 1; i < base + 1 + (n - 1 - (base + 1) + 1) / 2; i++) {
    const j = n - 1 - (i - (base + 1));
    swap(i, j);
  }

  return nums;
};

// console.log(nextPermutation([3, 2, 1]));
// console.log(nextPermutation());
console.log(nextPermutation(
  [2, 3, 1, 3, 3],
));
