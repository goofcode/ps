/**
 * @param {number} p
 * @param {number} q
 * @return {number}
 */
const mirrorReflection = (p, q) => {
  for (let k = q, i = 1; ; k += q, i++) {
    // left side and meet 2
    if (i % 2 === 0 && k % (2 * p) === p) {
      return 2;
    }
    // right side and meet 0
    if (i % 2 === 1 && k % (2 * p) === 0) {
      return 0;
    }
    // right side and meet 1
    if (i % 2 === 1 && k % (2 * p) === p) {
      return 1;
    }
  }
};

console.log(mirrorReflection(2, 1));
