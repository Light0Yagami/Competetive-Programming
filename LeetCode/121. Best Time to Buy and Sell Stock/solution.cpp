/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0],i;
        int profit = 0;
        for(int i = 1; i< prices.size(); i++){
            if(prices[i] - min < 0){
                min = prices[i];
            }else{
                profit = max(profit,prices[i] - min);
            }
        }
        return profit;
    }
};
