/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesis = (n) => {
  const results = [];

  const generate = (current, left, right, possible) => {
    if (current.length === n * 2) {
      results.push(current);
      return;
    }

    if (left > 0) {
      generate(`${current}(`, left - 1, right, possible + 1);
    }
    if (right > 0 && possible > 0) {
      generate(`${current})`, left, right - 1, possible - 1);
    }
  };

  generate('', n, n, 0);
  return results;
};

console.log(generateParenthesis(3));
