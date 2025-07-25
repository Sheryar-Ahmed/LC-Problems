class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int R = 1;
        int profit = 0;

        while(L < R && R < prices.size()){
            if(prices[L] < prices[R]){
                profit = max(profit, prices[R]-prices[L]);
            }else{
                L=R;
            }
            R++;
        }
        return profit;
    }
};