/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
const divide = (dividend, divisor) => {
  if (dividend === 0 || divisor === 0) return 0;
  if (dividend === -2147483648 && divisor === -1) return 2147483647;

  const sign = !((dividend > 0) ^ (divisor > 0));

  dividend = Math.abs(dividend);
  divisor = Math.abs(divisor);

  let result = 0;

  while (dividend >= divisor) {
    let count = 1;
    let maxDivisor = divisor;

    while (maxDivisor <= (dividend >> 1)) {
      maxDivisor <<= 1;
      count <<= 1;
    }

    result += count;
    dividend -= maxDivisor;
  }

  return sign ? result : -result;
};

console.log(divide(2147483647, -1));
