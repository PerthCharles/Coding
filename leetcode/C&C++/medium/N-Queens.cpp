/*
 *  N-Queens
 *      The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *      Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 *      Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 */


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->column = vector<int> (n, 0);
        this->main_diag = vector<int> (n*2, 0);
        this->anti_diag = vector<int> (n*2, 0);
        vector<vector<string> > result;
        vector<int> q_col(n, 0);  // q_col[i] means the ith queen is local at (i, q_col[i])
        dfs(q_col, result, 0);
        return result;
    }
    
private:
    vector<int> column;
    vector<int> main_diag;
    vector<int> anti_diag;
    
    void dfs(vector<int> &q_col, vector<vector<string> > &result, int row) {
        const int N = q_col.size();
        if (row == N) {
            vector<string> solution;
            string line(N, '.');
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j == q_col[i]) {
                        line[j] = 'Q';
                        solution.push_back(line);
                        line[j] = '.';
                        break;
                    }
                }
            }
            result.push_back(solution);
        } else {
            for (int j = 0; j < N; j++) {  // try each column
                bool ok = !(column[j] || main_diag[row + j] || anti_diag[row - j + N]);
                if (!ok) continue;
                q_col[row] = j;
                column[j] = main_diag[row+j] = anti_diag[row - j + N] = 1;
                dfs(q_col, result, row+1);
                column[j] = main_diag[row+j] = anti_diag[row - j + N] = 0;
            }
        }
    }
};