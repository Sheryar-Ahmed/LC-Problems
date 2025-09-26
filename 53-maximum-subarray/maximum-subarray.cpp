class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // with dp i think its gonna be O(n2)
        int n = nums.size();
        vector<int> dp(n); // largest sum at each index i
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};