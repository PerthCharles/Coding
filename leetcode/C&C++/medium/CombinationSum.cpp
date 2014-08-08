/*
 *  Combination Sum
 *      Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 *      The same repeated number may be chosen from C unlimited number of times.
 *
 *      Note:
 *      All numbers (including target) will be positive integers.
 *      Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *      The solution set must not contain duplicate combinations.
 *      For example, given candidate set 2,3,6,7 and target 7, 
 *      A solution set is: 
 *      [7] 
 *      [2, 2, 3] 
 */


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> combination;
        dfs(candidates, combination, target, result, 0);
        
        return result;
    }
private:
    void dfs(vector<int> &candidates, vector<int> &combination, int target,
             vector<vector<int> > &result, int from) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = from; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            
            combination.push_back(candidates[i]);
            dfs(candidates, combination, target-candidates[i], result, i);
            combination.pop_back();
        }
    }
};