class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];
        for(auto &curr: prices){
            maxP = max(maxP, curr-minBuy);
            minBuy = min(minBuy, curr);
        }

        return maxP;
    }
};