const maxRotateFunction = (A) => {
  const sum = A.reduce((acc, a) => acc + a, 0);
  const n = A.length;
  const F = [
    A.reduce((acc, a, i) => acc + a * i, 0),
  ];

  for (let i = n - 1; i > 0; i--) {
    F.push(F[F.length - 1] + sum - A[i] * n);
  }
  return Math.max(...F);
};
