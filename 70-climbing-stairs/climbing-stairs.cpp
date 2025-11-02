class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return helper(n, 0, dp);
    }
    int helper(int n, int i, vector<int>& dp){
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int one = helper(n, i+1, dp);
        int two = helper(n, i+2, dp);
        return dp[i] = one+two;
    }
};