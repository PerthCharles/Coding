/*
 *  Subsets II
 *      Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 *      Note:
 *      Elements in a subset must be in non-descending order.
 *      The solution set must not contain duplicate subsets.
 */


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> sub;
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        subsets(S, 0, sub, result);
        
        return result;
    }
private:
    void subsets(vector<int> &S, int item_id, vector<int> &sub, vector<vector<int> > &result) {
        if (item_id == S.size()) {
            result.push_back(sub);
            return;
        }
        if (sub.size() && S[item_id] == sub.back()) {
            sub.push_back(S[item_id]);
            subsets(S, item_id + 1, sub, result);
            sub.pop_back();
        } else {
            subsets(S, item_id + 1, sub, result);
            sub.push_back(S[item_id]);
            subsets(S, item_id + 1, sub, result);
            sub.pop_back();
        }
    }
};