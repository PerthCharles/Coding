/*
 * Best Time to Buy and Sell Stock
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *      If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max, buy, sell;
        int i, size;
        size = prices.size();
        
        if (size < 2) return 0;
        
        buy = prices[0];
        max = 0;
        for (i = 1; i < size; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                int profits;
                profits = prices[i] - buy;
                if (profits > max) max = profits;
            }
        }
        
        return max;
    }
};