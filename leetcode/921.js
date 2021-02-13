/**
 * @param {string} S
 * @return {number}
 */
const minAddToMakeValid = (S) => {
  let stack = 0;
  let fix = 0;

  for (const c of S) {
    if (c === '(') {
      stack++;
    } else if (stack > 0) {
      stack--;
    } else {
      fix++;
    }
  }

  fix += stack;
  return fix;
};
