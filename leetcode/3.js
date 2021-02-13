/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLongestSubstring = (s) => {
  let max = 0;
  let current = '';
  for (let l = 0, r = 0; r < s.length; r++) {
    while (current.includes(s[r])) {
      current = current.slice(1);
      l++;
    }
    current += s[r];
    max = Math.max(max, current.length);
  }
  return max;
};

console.log(lengthOfLongestSubstring(' '));
