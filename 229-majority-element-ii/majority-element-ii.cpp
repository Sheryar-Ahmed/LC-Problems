class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 1) return nums;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(auto &x: nums){
            mp[x]++;
        }
        vector<int> ans;
        for(auto &it: mp){
            if(it.second > floor(n/3)) ans.push_back(it.first);
        }
        return ans;
    }
};