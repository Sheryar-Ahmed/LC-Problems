class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int maxP = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                maxP = max(maxP, prices[right]-prices[left]);
            }else{
                left = right;
            }
            right++;
        }
        return maxP;
    }
};