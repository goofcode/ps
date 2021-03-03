/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const searchRange = (nums, target) => {
  const n = nums.length;

  // find lower bound
  const lower = (() => {
    let l = 0;
    let r = n - 1;

    while (l <= r) {
      const mid = Math.floor((l + r) / 2);

      if (nums[mid] === target) {
        r = mid - 1;
        if (nums[mid] !== nums[mid - 1]) {
          return mid;
        }
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  })();

  const upper = (() => {
    let l = 0;
    let r = n - 1;

    while (l <= r) {
      const mid = Math.floor((l + r) / 2);
      if (nums[mid] === target) {
        l = mid + 1;
        if (nums[mid] !== nums[mid + 1]) {
          return mid;
        }
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  })();

  return [lower, upper];
};

console.log(searchRange([5, 7, 7, 8, 8, 10], 8));
