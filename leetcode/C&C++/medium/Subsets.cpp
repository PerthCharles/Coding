/*
 *  Subsets
 *      Given a set of distinct integers, S, return all possible subsets.
 *
 *      Note:
 *      Elements in a subset must be in non-descending order.
 *      The solution set must not contain duplicate subsets.
 */


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, 0, path, result);
        return result;
    }
private:
    void subsets(vector<int> &S, int step, vector<int> &path, vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        
        // don't choose S[step]
        subsets(S, step + 1, path, result);
        // choose S[step]
        path.push_back(S[step]);
        subsets(S, step + 1, path, result);
        path.pop_back();  // clear S[step]
        return;
    }
};