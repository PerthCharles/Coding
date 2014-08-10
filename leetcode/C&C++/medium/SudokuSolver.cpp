/*
 *  Sudoku Solver
 *      Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 *      Empty cells are indicated by the character '.'.
 *
 *      You may assume that there will be only one unique solution.
 */

// Note: DFS


class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        board[i][j] = k + '0';
                        if (valid(board, i, j) && solve(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool valid(vector<vector<char> > &board, int x, int y) {
        // column x
        for (int j = 0; j < 9; j++) {
            if (j != y && board[x][j] == board[x][y]) return false;
        }
        
        // row y
        for (int i = 0; i < 9; i++) {
            if (i != x && board[i][y] == board[x][y]) return false;
        }
        
        // check the block contains (x, y)
        int beg_x = 3 * (x/3);
        int beg_y = 3 * (y/3);
        for (int i = beg_x; i < beg_x + 3; i++) {
            for (int j = beg_y; j < beg_y + 3; j++) {
                if (i == x && j == y) continue;
                if (board[i][j] == board[x][y]) return false;
            }
        }
        
        return true;
    }
};