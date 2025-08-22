class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        return min(solve(n-1, memo, cost), solve(n-2, memo, cost));
    }
    int solve(int n, vector<int>& memo, vector<int>& cost){
        if(memo[n] != -1) return memo[n];
        if(n == 0 || n == 1) return cost[n];
        return memo[n] = cost[n] + min(solve(n-1, memo, cost), solve(n-2, memo, cost));
    }
};
