/*
 *  Spiral Matrix
 *      Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 *      For example,
 *      Given the following matrix:
 *
 *      [
 *       [ 1, 2, 3 ],
 *       [ 4, 5, 6 ],
 *       [ 7, 8, 9 ]
 *      ]
 *      You should return [1,2,3,6,9,8,7,4,5].
 */



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        if (matrix[0].empty()) return result;
        
        int begin = 0;
        int endY = matrix[0].size() - 1;    // column number for the cycle
        int endX = matrix.size() - 1;       // row number for the cycle
        
        while (begin < endY && begin < endX) {
            for (int j = begin; j < endY; j++) result.push_back(matrix[begin][j]);
            for (int i = begin; i < endX; i++) result.push_back(matrix[i][endY]);
            for (int j = endY; j > begin; j--) result.push_back(matrix[endX][j]);
            for (int i = endX; i > begin; i--) result.push_back(matrix[i][begin]);
            begin++;
            endX--;
            endY--;
        }
        if (begin == endY && begin <= endX) {     // left only one column
            while (begin <= endX) result.push_back(matrix[begin++][endY]);
        }
        if (begin == endX && begin <= endY) {     // left only one row
            while (begin <= endY) result.push_back(matrix[endX][begin++]);
        }
        
        return result;
    }
};