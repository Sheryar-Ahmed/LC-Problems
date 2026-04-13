/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    if(nums.length < 2) return false;
    // with sort
    nums.sort((a,b) => a-b);
    for(let i=0; i < nums.length; i++){
        if(i > 0 && nums[i] == nums[i-1]) return true;
    }
    return false;
    // with set
    // let set = new Set();
    // for(x of nums){
    //     if(set.has(x)){
    //         return true;
    //     }
    //     set.add(x);
    // }
    // return false;
};