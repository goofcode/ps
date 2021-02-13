/**
 * @param {number[]} encoded
 * @return {number[]}
 */
const decode = (encoded) => {
  const n = encoded.length + 1;
  const allXor = (n % 4 === 3) ? 0 : 1;
  const a = Array(n).fill(null);

  a[0] = encoded.reduce((acc, e, i) => {
    if (i % 2 === 1) {
      acc ^= e;
    }
    return acc;
  }, allXor);

  for (let i = 1; i < n; i++) {
    a[i] = a[i - 1] ^ encoded[i - 1];
  }

  return a;
};

console.log(decode([6, 5, 4, 6]));
