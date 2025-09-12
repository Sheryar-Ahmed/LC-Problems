class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] != target) return -1;
        unordered_map<int, int> mp;
        for(int i=0; i< nums.size();i++){
            mp[nums[i]] = i;
            if(mp.find(target) != mp.end()){
                return mp[target];
            }
        }
        return -1;
    }
};