/**
 * @param {character[][]} board
 * @return {boolean}
 */
const isValidSudoku = (board) => {
  // naive approach
  const rowStart = new Array(9).fill(null).map((e, i) => [i, 0]);
  const colStart = new Array(9).fill(null).map((e, i) => [0, i]);
  const boxStart = new Array(9).fill(null).map((e, i) => [Math.floor(i / 3) * 3, (i % 3) * 3]);

  const rowMove = new Array(9).fill(null).map((e, i) => [0, i]);
  const colMove = new Array(9).fill(null).map((e, i) => [i, 0]);
  const boxMove = new Array(9).fill(null).map((e, i) => [Math.floor(i / 3), i % 3]);

  const check = (start, move) => {
    for (let i = 0; i < start.length; i++) {
      const [sy, sx] = start[i];
      const appear = new Array(9).fill(false);
      for (let j = 0; j < move.length; j++) {
        const [cy, cx] = move[j];
        const n = Number(board[sy + cy][sx + cx]);

        if (isNaN(n)) {
          continue;
        }

        if (appear[n + 1]) {
          return false;
        }

        appear[n + 1] = true;
      }
    }
    return true;
  };

  return check(rowStart, rowMove) && check(colStart, colMove) && check(boxStart, boxMove);
};

console.log(isValidSudoku(
  [['8', '3', '.', '.', '7', '.', '.', '.', '.'],
    ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
    ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
    ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
    ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
    ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
    ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
    ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
    ['.', '.', '.', '.', '8', '.', '.', '7', '9']],
));
