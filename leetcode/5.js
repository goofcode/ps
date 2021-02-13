/**
 * @param {string} s
 * @return {string}
 */
const longestPalindrome = (s) => {
  const n = s.length;
  // const result = Array(n).fill(null).map((e) => Array(n + 1).fill(null));
  // let longest = { s: 0, e: 1 };

  // for (let i = 0; i < n; i++) {
  //   result[i][i] = 0;
  //   result[i][i + 1] = 1;
  // }

  // for (let i = 2; i < n + 1; i++) {
  //   for (let start = 0; i + start <= n; start++) {
  //     const end = i + start;
  //     const last = result[start + 1][end - 1];
  //     if (last !== null && s[start] === s[end - 1]) {
  //       result[start][end] = last + 2;
  //       if (result[start][end] > (longest.e - longest.s)) {
  //         // longest = s.slice(start, end);
  //         longest = { s: start, e: end };
  //       }
  //     }
  //   }
  // }

  // return s.slice(longest.s, longest.e);

  let longest = s[0];

  const palindrome = (l, r) => {
    while (l >= 0 && r < n && s[l] === s[r]) {
      l--; r++;
    }
    return s.slice(l + 1, r);
  };

  for (let i = 0; i < n; i++) {
    const odd = palindrome(i, i);
    const even = palindrome(i, i + 1);

    const longer = odd.length > even.length ? odd : even;
    if (longer.length > longest.length) {
      longest = longer;
    }
  }

  return longest;
};

console.log(longestPalindrome('babad'));
console.log(longestPalindrome('cbbd'));
console.log(longestPalindrome('ac'));
console.log(longestPalindrome('a'));
