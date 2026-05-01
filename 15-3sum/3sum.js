/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    let target = 0;
    // as we know we can do this in O(N^2) how we can fix one do the two pointer technique here
    let len = nums.length;
    // sort the nums as well
    let ans = [];
    nums.sort((a, b) => a - b);
    for (let i = 0; i < len - 2; i++) {
        // check for duplicates and skip
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        let l = i + 1;
        let r = len - 1;
        while (l < r) {
            let sum = nums[l] + nums[r] + nums[i];
            if (sum == target) {
                ans.push([nums[l], nums[r], nums[i]])
                l++
                r--;
                while (nums[l] == nums[l - 1]) l++;
                while (nums[r] == nums[r + 1]) r--;
            }
            else if (sum < target) {
                l++
            }
            else if (sum > target) {
                r--
            }
        }
    }
    return ans;
};