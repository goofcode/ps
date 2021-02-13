const arrayPairSum = (nums) => {
  nums.sort((a, b) => a - b);
  let sum = 0;
  console.log(nums);
  for (let i = 0; i < nums.length; i++) {
    if (i % 2 === 0) {
      sum += nums[i];
    }
  }
  return sum;
};

console.log(arrayPairSum(
  [6214, -2290, 2833, -7908],
));
