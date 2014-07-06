/*
 * Unique Paths
 *      A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 *      The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 *      How many possible unique paths are there?
 */


class Solution {
private:
    vector<vector<int> > buf;
    
public:
    
    /* Method one: Memo
     int uniquePaths(int m, int n) {
     this->buf = vector<vector<int> >(m+1, vector<int>(n+1, 0));
     return dfs(m, n);
     }
     
     int dfs(int m, int n) {
     if (m == 1 || n == 1) return 1;
     if (buf[m][n] > 0) return buf[m][n];
     
     if (buf[m-1][n] == 0) buf[m-1][n] = dfs(m-1, n);
     if (buf[m][n-1] == 0) buf[m][n-1] = dfs(m, n-1);
     return buf[m][n] = buf[m-1][n] + buf[m][n-1];
     }
     */
    int uniquePaths(int m, int n) {
        vector<int> buf(n, 0);
        buf[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                buf[j] = buf[j-1] + buf[j];
            }
        }
        
        return buf[n-1];
    }
};