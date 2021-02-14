/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const threeSumClosest = (nums, target) => {
  const n = nums.length;
  let diff = Number.MAX_SAFE_INTEGER;
  let result = 0;

  nums.sort((l, r) => l - r);
  for (let i = 0; i < n - 2; i++) {
    let j = i + 1;
    let k = n - 1;
    while (j < k) {
      const sum = nums[i] + nums[j] + nums[k];
      if (sum === target) {
        return sum;
      }

      const curDiff = Math.abs(target - sum);
      if (curDiff < diff) {
        diff = curDiff;
        result = sum;
      }

      if (sum > target) k--;
      else j++;
    }
  }

  return result;
};
