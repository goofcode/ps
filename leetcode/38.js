/**
 * @param {number} n
 * @return {string}
 */
const countAndSay = (n) => {
  let str = '1';
  for (let i = 0; i < n - 1; i++) {
    let current = str[0];
    let count = 1;
    let result = '';
    for (let j = 1; j < str.length; j++) {
      if (current !== str[j]) {
        result += `${count}${current}`;
        current = str[j];
        count = 1;
        continue;
      }
      count++;
    }
    if (count !== 0) { result += `${count}${current}`; }
    str = result;
  }
  return str;
};

console.log(countAndSay(4));
