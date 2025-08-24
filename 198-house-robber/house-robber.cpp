class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(n-1, memo, nums);
    }

    int solve(int i, vector<int>& memo, vector<int>& nums){
        if(i < 0) return 0;          // no houses left
        if(memo[i] != -1) return memo[i];

        // rob this house or skip it
        return memo[i] = max(nums[i] + solve(i-2, memo, nums),
                             solve(i-1, memo, nums));
    }
};
