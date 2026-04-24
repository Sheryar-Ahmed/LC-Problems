/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    if(nums.length == 0) return 0;
    nums.sort((a, b) => a - b);
    console.log(nums);
    let max = 1;
    let curr = 1;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) continue; // duplicated
        if (i > 0 && nums[i - 1] == nums[i] - 1) {
            curr += 1;
            max = Math.max(max, curr);
        } else {
            curr = 1;
        }
    }
    return max;
};