class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i <= amount; i++){
            // let' start with coins if we are able to make the amount
            for(auto c: coins){
                if(i-c >=0 &&  dp[i-c] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};