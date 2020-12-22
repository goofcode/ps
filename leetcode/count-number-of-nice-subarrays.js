const numberOfSubarrays = function(nums, k) {
    let count = 0;
    let intervals = [];
    let start = 0;
    for (let i =0;i <= nums.length; i++) {
        if (nums[i] % 2 === 1 || i === nums.length) {
            intervals.push(i-start);
            start = i + 1;
            if (intervals.length === k+1) {
                const leftMargin = intervals.shift();
                const rightMargin = intervals[intervals.length - 1];
                count += (leftMargin + 1) * (rightMargin + 1);
            }
        }
    }
    return count;
};

console.log(numberOfSubarrays([1,1,2,1,1], 3));
console.log(numberOfSubarrays([2,4,6], 1));
console.log(numberOfSubarrays([2,2,2,1,2,2,1,2,2,2], 2));
