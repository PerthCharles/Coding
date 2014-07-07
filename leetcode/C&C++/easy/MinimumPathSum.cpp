/*
 * Minimum Path Sum
 *      Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 *      Note: You can only move either down or right at any point in time.
 */


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row, col, m, n, result;
        m = grid.size();
        n = grid[0].size();
        if (m <=0 || n <= 0) return 0;
        vector<int> buf(n);
        
        // init buf
        for (col = 0; col < n; col++) {
            if (col == 0) buf[col] = grid[0][col];
            else buf[col] = buf[col-1] + grid[0][col];
        }
        
        for (row = 1; row < m; row++) {
            for (col = 0; col < n; col++) {
                if (col == 0) buf[col] = buf[col] + grid[row][col];
                else buf[col] = min(buf[col-1], buf[col]) + grid[row][col];
            }
        }
        
        return buf[n-1];
    }
    
private:
    int min(int a, int b) {
        return (a <= b) ? a : b;
    }
};