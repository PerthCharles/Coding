/*
 *  Candy
 *      There are N children standing in a line. Each child is assigned a rating value.
 *
 *      You are giving candies to these children subjected to the following requirements:
 *
 *      Each child must have at least one candy.
 *      Children with a higher rating get more candies than their neighbors.
 *      What is the minimum candies you must give?
 */


class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        if (n < 2) return n;
        vector<int> dis(n, 1);   // distribution
        
        // scan from left
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                dis[i] = max(dis[i], dis[i-1] + 1);
            }
            // if ratings[i] == ratings[i-1]
            // both dis[i] >= dis[i-1] and dis[i] < dis[i-1] is OK!
        }
        // scan from right
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                dis[i] = max(dis[i], dis[i+1] + 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dis[i];
        }
        
        return sum;
    }
};