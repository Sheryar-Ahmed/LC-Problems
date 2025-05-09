class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Rob either from 0 to n-2 OR from 1 to n-1
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
