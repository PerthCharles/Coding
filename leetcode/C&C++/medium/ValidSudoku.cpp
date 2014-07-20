/*
 *  Valid Sudoku
 *      Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules[http://sudoku.com.au/TheRules.aspx].
 *
 *      The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 *      Note:
 *      A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int flag[9], tmp;
        int i, j, row, col;
        
        if ((row = board.size()) != 9) return false;
        if ((col = board[0].size()) != 9) return false;
        
        // check each row
        for (i = 0; i < 9; i++) {
            flag[i] = 0;
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                tmp = 1 << (int)(board[i][j] - '0');
                if (tmp & flag[i]) {
                    return false;
                }
                flag[i] |= tmp;
            }
        }
        
        // check each column
        for (j = 0; j < 9; j++) {
            flag[j] = 0;
            for (i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                
                tmp = 1 << (int)(board[i][j] - '0');
                if (tmp & flag[j]) {
                    return false;
                }
                flag[j] |= tmp;
            }
        }
        
        for (i = 0; i < 9; i++) {
            flag[i] = 0;
        }
        // check each block
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                tmp = 1 << (int)(board[i][j] - '0');
                if (tmp & flag[i/3 + 3*(j/3)]) return false;
                flag[i/3 + 3*(j/3)] |= tmp;
            }
        }
        
        return true;
    }
};