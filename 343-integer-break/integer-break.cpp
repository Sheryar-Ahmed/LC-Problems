class Solution {
public:
    vector<int> memo;
    int integerBreak(int n) {
        memo.resize(n+1, -1);
        return solve(n);
    }
    int solve(int n){
        if(n == 1) return 1; // further cannot be divided
        if(memo[n] != -1) return memo[n];
        // break integer into pairs of i, n-i;
        int result = INT_MIN;
        for(int i=1; i <= n-1; i++){
            int prod = i* max(n-i, solve(n-i));
            result = max(prod, result);
        }
        return memo[n] = result;
    }
};