const countVowelStrings = (n) => {
  const arr = Array(n).fill(null).map(() => Array(5).fill(1));

  arr[0] = [1, 2, 3, 4, 5];

  for (let i = 1; i < n; i++) {
    for (let j = 1; j < 5; j++) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

  return arr[n - 1][4];
};

console.log(countVowelStrings(33));
