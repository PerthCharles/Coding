/*
 *  Triangle
 *      Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 */


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 0) return 0;
        if (triangle[0].size() == 0) return 0;
        int i, j;
        
        for (i = row-2; i >= 0; i--) {
            for (j = 0; j <= i; j++) {  // i starts from 0, so there are (i+1) items in line i
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
        
    }
private:
    int min(int a, int b) {
        return a <= b ? a : b;
    }
};