/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
const multiply = (num1, num2) => {
  if (num1 === '0' || num2 === '0') return '0';

  const n = num1.length;
  const m = num2.length;
  const result = new Array(n + m).fill(0);

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      const base = n + m - 1 - (i + j);

      const sum = result[base] + Number(num1[n - 1 - i]) * Number(num2[m - 1 - j]);
      result[base] = sum % 10;
      result[base - 1] += Math.floor(sum / 10);
    }
  }

  if (result[0] === 0) result.shift();
  return result.join('');
};

console.log(multiply('123', '456'));
