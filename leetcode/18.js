/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
const fourSum = (nums, target) => {
  const n = nums.length;
  const result = [];

  nums.sort((l, r) => l - r);

  for (let i = 0; i < n - 3; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) {
      continue;
    }
    const a = nums[i];
    for (let j = i + 1; j < n - 2; j++) {
      if (j > i + 1 && nums[j] === nums[j - 1]) {
        continue;
      }
      const b = nums[j];

      let l = j + 1;
      let r = n - 1;
      while (l < r) {
        const c = nums[l];
        const d = nums[r];
        const sum = a + b + c + d;

        if (sum === target) {
          result.push([a, b, c, d]);
          l++; r--;
          while (l < r && nums[l] === nums[l - 1]) l++;
          while (l < r && nums[r] === nums[r + 1]) r--;
        } else if (sum < target) {
          l++;
        } else {
          r--;
        }
      }
    }
  }
  return result;
};

console.log(JSON.stringify(fourSum([-2, -1, -1, 1, 1, 2, 2], 0)));
