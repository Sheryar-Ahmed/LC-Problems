class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return solve(memo, n);
    }
    int solve (vector<int>& memo, int n){
        if(n < 2) return 1;
        if(memo[n] != -1) return memo[n];
        return memo[n] = solve(memo, n-1)+solve(memo, n-2); // febonacci related problem
    }
};