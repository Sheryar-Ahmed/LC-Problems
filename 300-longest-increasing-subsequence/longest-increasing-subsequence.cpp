class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] will basically be the max longest increasing subsequence upto index i;
        int n = nums.size();
        if(n < 1) return -1;
        if(n <= 1) return 1;
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for(int j=0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};