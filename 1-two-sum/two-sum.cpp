class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() <= 1 && nums[0] != target) return {};
        unordered_map<int, int> look_past;
        for(int i=0; i < nums.size(); i++){
            int rem = target-nums[i];
            if(look_past.find(rem) != look_past.end()){
                return {look_past[rem], i};
            }
            // just store the element and its index
            look_past[nums[i]] = i;
        }
        // if not found just return and empty
        return {};
    }
};