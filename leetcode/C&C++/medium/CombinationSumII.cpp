/*
 *  Combination Sum II
 *      Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 *      Each number in C may only be used once in the combination.
 *
 *      Note:
 *      All numbers (including target) will be positive integers.
 *      Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *      The solution set must not contain duplicate combinations.
 *      For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 *      A solution set is: 
 *      [1, 7] 
 *      [1, 2, 5] 
 *      [2, 6] 
 *      [1, 1, 6] 
 */


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> combination;
        
        dfs(num, combination, result, target, 0);
        
        return result;
    }
    
private:
    void dfs(vector<int> &num, vector<int> &combination, vector<vector<int> > &result, int target, int from) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        int previous = -1;
        for (int i = from; i < num.size(); i++) {
            // if num[i] isn't choosed by the previous loop,
            // then don't choose num[i] in this loop
            if (num[i] == previous) continue;
            
            if (num[i] > target) return;
            previous = num[i];
            combination.push_back(num[i]);
            dfs(num, combination, result, target - num[i], i+1);
            combination.pop_back();
        }
    }
};