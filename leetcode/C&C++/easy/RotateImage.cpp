/*
 * Rotate Image
 *      You are given an n x n 2D matrix representing an image.
 *
 *      Rotate the image by 90 degrees (clockwise).
 *
 *      Follow up:
 *      Could you do this in-place?
 */


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int i, j, n;
        int tmp;
        
        n = matrix.size();
        // transposition
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // reverse
        for (j = 0; j < n/2; j++) {
            for (i = 0; i < n; i++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};