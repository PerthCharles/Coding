/*
 * Pascal's Triangle (Yanghui's Triangle)
 *      Given numRows, generate the first numRows of Pascal's triangle.
 */


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        int i, j;
        
        if (numRows == 0) return result;
        result.push_back(vector<int> (1, 1));
        for (i = 2; i <= numRows; i++) {
            vector<int> &prev = result[(i-1) - 1];
            vector<int> item(i, 1);
            for (j = 1; j < i - 1; j++) {
                item[j] = prev[j-1] + prev[j];
            }
            result.push_back(item);
        }
        
        return result;
    }
};