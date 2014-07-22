/*
 *  3Sum Closest
 *      Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *          For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *              The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int min_gap = INT_MAX;
        int i, j, k;
        int result;
        
        sort(num.begin(), num.end());
        
        for (i = 0; i < num.size() - 2; i++) {
            j = i+1;
            k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                int gap = abs(sum - target);
                if (sum == target) return target;
                if (gap < min_gap) {
                    result = sum;
                    min_gap = gap;
                }
                
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        return result;
    }
};