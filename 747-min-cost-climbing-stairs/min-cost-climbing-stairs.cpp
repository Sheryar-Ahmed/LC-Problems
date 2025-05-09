class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& memo){
        if(memo[n] != -1) return memo[n];
        if(n == 0 or n == 1) return cost[n];
        return memo[n] = cost[n]+min(solve(n-1, cost, memo), solve(n-2, cost, memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n+1, -1); // filled with -1, size n+1;
        return min(solve(n-1, cost, memo), solve(n-2, cost, memo));
    }
};