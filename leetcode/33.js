/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const search = (nums, target) => {
  const n = nums.length;

  let l = 0;
  let r = n - 1;
  while (l <= r) {
    const mid = Math.floor((r + l) / 2);

    if (nums[mid] === target) {
      return mid;
    }
    if (nums[l] <= nums[mid]) {
      if (nums[l] <= target && target <= nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else {
      // eslint-disable-next-line no-lonely-if
      if (nums[mid] <= target && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return -1;
};

search(
  [3, 1],
  1,
);
