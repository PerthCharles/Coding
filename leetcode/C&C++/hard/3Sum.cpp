/*
 *  3Sum
 *      Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 *      Note:
 *      Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *      The solution set must not contain duplicate triplets.
 *          For example, given array S = {-1 0 1 2 -1 -4},
 *
 *              A solution set is:
 *              (-1, 0, 1)
 *              (-1, -1, 2)
 */


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        int target = 0;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());
        
        for (int a = 0; a < num.size() - 2; a++) {
            int b = a+1;
            int c = num.size()-1;
            while (b < c) {
                int tmp = num[a] + num[b] + num[c];
                if (tmp == target) {
                    vector<int> tmp;
                    tmp.push_back(num[a]);
                    tmp.push_back(num[b]);
                    tmp.push_back(num[c]);
                    result.push_back(tmp);
                    b++;
                    c--;
                } else if (tmp < target) {
                    b++;
                } else if (tmp > target) {
                    c--;
                }
            }
        }
        sort(result.begin(), result.end());
        auto it = unique(result.begin(), result.end());
        result.resize(distance(result.begin(), it));
        return result;
    }
};