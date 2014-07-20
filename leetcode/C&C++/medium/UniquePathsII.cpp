/*
 * Unique Paths II
 *      Follow up for "Unique Paths":
 *
 *      Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 *      An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 */


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        if (row == 0) return 0;
        int col = obstacleGrid[0].size();
        if (col == 0) return 0;
        int i, j;
        vector<int> buf(row, 0);
        
        for (i = 0; i < row; i++) {
            if (obstacleGrid[i][0] == 0) {
                if (i == 0) buf[i] = 1;
                else buf[i] = buf[i-1];
            }
        }
        
        for (j = 1; j < col; j++) {
            for (i = 0; i < row; i++) {
                if (obstacleGrid[i][j] == 1) {
                    buf[i] = 0;
                } else {
                    if (i > 0) buf[i] = buf[i] + buf[i-1];
                }
            }
        }
        
        return buf[row-1];
    }
};