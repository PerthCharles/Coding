/*
 *  4Sum
 *      Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 *      Note:
 *      Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *      The solution set must not contain duplicate quadruplets.
 *          For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *              A solution set is:
 *                  (-1,  0, 0, 1)
 *                  (-2, -1, 1, 2)
 *                  (-2,  0, 0, 2)
 */



// TODO: learn more about STL in C++

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) return result;
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int> > > cache;
        
        for (int i = 0; i < num.size()-1; i++) {
            for (int j = i+1; j < num.size(); j++) {
                cache[num[i] + num[j]].push_back(pair<int, int>(i, j));
            }
        }
        
        for (int c = 0; c < num.size()-1; c++) {
            for (int d = c+1; d < num.size(); d++) {
                int key = target - num[c] - num[d];
                if (cache.find(key) == cache.end()) continue;
                
                vector<pair<int, int> > candidates = cache[key];
                for (int k = 0; k < candidates.size(); k++) {
                    if (c <= candidates[k].second) continue;
                    
                    result.push_back( {num[candidates[k].first], num[candidates[k].second], num[c], num[d]} );
                }
            }
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};