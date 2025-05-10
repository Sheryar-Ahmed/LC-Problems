class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;

        // Iterate through each coin
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                // If using this coin reduces the amount, update the minimum number of coins needed
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }

};