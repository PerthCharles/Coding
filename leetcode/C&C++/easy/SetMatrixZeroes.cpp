/*
 * Set Matrix Zeroes
 *      Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_fr = 0, flag_fc = 0;  // flag for the first row and colomn
        int i, j;
        
        // init flag for the first col and row
        for (i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                flag_fc = 1;
                break;
            }
        }
        for (j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                flag_fr = 1;
                break;
            }
        }
        
        // use the first col and row as bitmap
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // set matrix by first col and first row
        for (i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (flag_fc == 1) {
            for (i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_fr == 1) {
            for (j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};