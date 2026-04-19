/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    // for each index we will store its prefix and postfix 
    // multiply the prefix and postfix to get that index that's all
    const n = nums.length;
    const result = new Array(n);

    // Step 1: prefix products
    result[0] = 1;
    for (let i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Step 2: postfix products
    let postfix = 1;
    for (let i = n - 1; i >= 0; i--) {
        result[i] = result[i] * postfix;
        postfix *= nums[i];
    }

    return result;
};