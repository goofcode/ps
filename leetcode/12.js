/**
 * @param {number} num
 * @return {string}
 */
const intToRoman = (num) => {
  const digits = [];
  let result = '';
  for (let i = 3; i >= 0; i--) {
    const div = 10 ** i;
    digits.push(Math.floor(num / div));
    num %= div;
  }

  const single = ['M', 'C', 'X', 'I'];
  const five = [null, 'D', 'L', 'V'];

  for (let i = 0; i < 4; i++) {
    const d = digits[i];
    let current;
    if (d === 4) current = single[i] + five[i];
    else if (d === 9) current = single[i] + single[i - 1];
    else if (d < 5) current = single[i].repeat(d);
    else if (d < 9) current = five[i] + single[i].repeat(d - 5);
    result += current;
  }

  return result;
};
