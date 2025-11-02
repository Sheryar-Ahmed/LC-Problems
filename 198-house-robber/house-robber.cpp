class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, dp);
    }
    int helper(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        // skip current
        int skip = helper(nums, i+1, dp);
        // rob 
        int rob = nums[i]+helper(nums, i+2, dp);
        return dp[i] = max(skip, rob);
    }
};