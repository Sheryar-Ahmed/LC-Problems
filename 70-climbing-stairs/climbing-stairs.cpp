class Solution {
public:
        vector<int> memo;
    int climbStairs(int n) {
        memo.resize(n, -1);
        return dfs(n, 0);
    }
    int dfs(int n, int step){
        if(step > n) return 0;
        if(step == n) return 1;
        if(memo[step] != -1) return memo[step];
        int res1 = dfs(n, step+1);
        int res2 = dfs(n, step+2);
        return memo[step] = res1+res2;
    }
};