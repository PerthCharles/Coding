/*
 * Search a 2D Matrix 
 *      Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 *      Integers in each row are sorted from left to right.
 *      The first integer of each row is greater than the last integer of the previous row.
 */


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int from = 0, to = m * n, mid;
        
        while (from < to) {
            mid = (from + to)/2;
            if (matrix[mid/n][mid%n] == target) {
                return true;
            } else if (matrix[mid/n][mid%n] > target) {
                to = mid;
            } else {
                from = mid + 1;
            }
        }
        
        return false;
    }
};