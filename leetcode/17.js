/**
 * @param {string} digits
 * @return {string[]}
 */
const letterCombinations = (digits) => {
  const chars = [null, null,
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
    ['m', 'n', 'o'],
    ['p', 'q', 'r', 's'],
    ['t', 'u', 'v'],
    ['w', 'x', 'y', 'z'],
  ];
  const result = [];

  const dfs = (current, leftDigits) => {
    if (leftDigits.length === 0) {
      result.push(current);
      return;
    }

    const d = leftDigits.shift();
    chars[d].forEach((c) => {
      dfs(current + c, leftDigits);
    });
    leftDigits.unshift(d);
  };

  if (!digits) {
    return [];
  }

  dfs('', digits.split('').map((e) => parseInt(e, 10)));
  return result;
};

console.log(letterCombinations(''));
