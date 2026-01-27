class Solution {
public:
    vector<int> dp;

    int dfs(int i, vector<int>& cost) {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // we have two choices initially either from index 0 or 1
        // then we have choices at each step either i+1, or i+2; we can take the
        // minimum at that position and store that in our dp[i] and our base
        // condition would be i > cost.size(); then we will return moreover this
        // is sufficient just do the recursion first will add dp letter at start
        // we can also have min(dfs(0), dfs(1)); and then in each dfs we have
        // i+1, i+2;
        dp.assign(cost.size(), -1);
        return min(dfs(0, cost), dfs(1, cost));
    }
};