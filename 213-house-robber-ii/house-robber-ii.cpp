class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int len = end - start + 1;
        if (len == 1) return nums[start];
        
        vector<int> dp(len);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < len; i++) {
            dp[i] = max(nums[start + i] + dp[i - 2], dp[i - 1]);
        }

        return dp[len - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
