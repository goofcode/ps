/**
 * @param {number[]} height
 * @return {number}
 */
const maxArea = (height) => {
  const n = height.length;
  let l = 0;
  let r = n - 1;
  let max = 0;

  while (l < r) {
    const current = (r - l) * Math.min(height[l], height[r]);
    max = Math.max(max, current);
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }
  return max;
};
