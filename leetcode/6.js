/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = (s, numRows) => {
  if (numRows === 1) return s;
  const result = Array(numRows).fill(null).map(() => []);
  for (let i = 0; i < s.length; i++) {
    const rem = i % (2 * numRows - 2);
    const pos = rem < numRows ? rem : (2 * numRows - 2 - rem);
    result[pos].push(s[i]);
  }
  return result.reduce((acc, l) => acc += l.join(''), '');
};

console.log(convert('ABC', 1));
