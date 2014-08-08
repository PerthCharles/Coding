/*
 *  Best Time to Buy and Sell Stock III
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *      Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 *      Note:
 *      You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int N = prices.size();
        if (N < 2) return 0;
        vector<int> left(N, 0);     // left[i] is the max profit of [0, i]
        vector<int> right(N, 0);    // right[i] is the max profit of [i, N-1]
        int low = prices[0], high = prices[N-1], profit = 0;
        
        for (int i = 1; i < N; i++) {
            low = min(low, prices[i]);
            left[i] = max(left[i-1], prices[i] - low);
        }
        for (int i = N - 2; i >= 0; i--) {
            high = max(high, prices[i]);
            right[i] = max(right[i+1], high - prices[i]);
        }
        
        for (int mid = 0; mid < N; mid++) {    // [0, mid], [mid, N)
            profit = max(profit, left[mid] + right[mid]);
        }
        
        return profit;
    }
private:
    int min(int a, int b) {
        return a <= b ? a : b;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
};