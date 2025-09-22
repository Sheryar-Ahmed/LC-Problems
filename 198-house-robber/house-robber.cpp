class Solution {
vector<int> dp;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
    int solve(int n, vector<int>& nums){
        if(n >= nums.size()) return 0;
        if(dp[n] != -1) return dp[n];
        // rob current house
        int robCurr = nums[n]+solve(n+2, nums); // we can rob the next one.
        int skipCurr = solve(n+1, nums); // immediatly rob the nextone;
        return dp[n] = max(robCurr, skipCurr);
    }
};