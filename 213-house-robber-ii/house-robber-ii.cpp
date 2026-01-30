class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n < 2) return nums[0];
        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);

        int rob1 = helper(n - 2, nums, 0, memo1);
        int rob2 = helper(n - 1, nums, 1, memo2);

        return max(rob1, rob2);
    }
    int helper(int end, vector<int>& nums, int i, vector<int>& dp) {
        if (i > end)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        // skip current
        int skip = helper(end, nums, i + 1, dp);
        // rob
        int rob = nums[i] + helper(end, nums, i + 2, dp);
        return dp[i] = max(skip, rob);
    }
};