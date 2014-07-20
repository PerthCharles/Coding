/*
 *  Spiral Matrix II
 *      Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 *      For example,
 *      Given n = 3,
 *
 *      You should return the following matrix:
 *      [
 *       [ 1, 2, 3 ],
 *       [ 8, 9, 4 ],
 *       [ 7, 6, 5 ]
 *      ]
 */


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        int begin = 0, end = n-1;
        int cnt = 1;
        
        while (begin < end) {
            for (int j = begin; j < end; j++) result[begin][j] = cnt++;
            for (int i = begin; i < end; i++) result[i][end] = cnt++;
            for (int j = end; j > begin; j--) result[end][j] = cnt++;
            for (int i = end; i > begin; i--) result[i][begin] = cnt++;
            begin++;
            end--;
        }
        if (begin == end) result[begin][begin] = cnt;
        
        return result;
    }
};