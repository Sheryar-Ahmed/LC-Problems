class Solution {
public:
    int robFrom(int i, int end, vector<int>& nums, vector<int>& memo) {
        if (i > end) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = max(nums[i] + robFrom(i + 2, end, nums, memo),
                             robFrom(i + 1, end, nums, memo));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> memo1(n, -1);  // rob from 0 to n-2
        vector<int> memo2(n, -1);  // rob from 1 to n-1

        int rob1 = robFrom(0, n - 2, nums, memo1);  // exclude last
        int rob2 = robFrom(1, n - 1, nums, memo2);  // exclude first

        return max(rob1, rob2);
    }
};
