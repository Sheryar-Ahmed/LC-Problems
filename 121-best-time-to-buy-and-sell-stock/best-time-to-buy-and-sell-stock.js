/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if(prices.length < 2) return 0;
    let l = 0; // buy
    let r = 1; // sell
    let profit = 0;
    for(let i=0; i < prices.length; i++){
        if(prices[l] < prices[r]){
            profit = Math.max(profit, prices[r] - prices[l]);
        } else{
            l = r;
        }
        r+=1;
    }
    return profit;
};