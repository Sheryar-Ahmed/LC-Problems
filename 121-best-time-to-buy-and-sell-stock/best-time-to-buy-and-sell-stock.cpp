class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int R = 1;
        int maxP = 0;
        while(R < prices.size()) {
            if(prices[L] < prices[R]){
                int profit = prices[R] - prices[L];
                maxP = max(maxP, profit);
            }else {
                L = R;
            }
            R++;
        }
        return maxP;
    }
};