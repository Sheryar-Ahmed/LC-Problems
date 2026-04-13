/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    if(nums.length < 2) return false;
    let set = new Set();
    for(x of nums){
        if(set.has(x)){
            return true;
        }
        set.add(x);
    }
    return false;
};