/*
 *  Combinations
 *      Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 */


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> combination;
        int i;
        if (n < k) return result;
        for (i = 1; i <= k; i++) {
            combination.push_back(i);
        }
        result.push_back(combination);
        
        while (next_combination(combination, n, k) == 1) {
            result.push_back(combination);
        }
        
        return result;
    }
    
private:
    int next_combination(vector<int> &combination, int n, int k) {
        int i, hasnext = 0;
        int tmp;
        for (i = k - 1; i >= 0; i--) {
            if (combination[i] < (n - k  + 1) + i) {
                hasnext = 1;
                tmp = combination[i];
                while (i < k) {
                    combination[i++] =(++tmp);
                }
                return hasnext;
            }
        }
        
        return hasnext;
    }
};