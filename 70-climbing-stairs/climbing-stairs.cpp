class Solution {
vector<int> dp;
public:
    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return helper(n);
    }
    int helper(int n){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1)+helper(n-2);
    }
};