/*
 *  N-Queens II
 *      Follow up for N-Queens problem.
 *
 *      Now, instead outputting board configurations, return the total number of distinct solutions.
 */


class Solution {
public:
    int totalNQueens(int n) {
        this->column = vector<int> (n, 0);
        this->main_diag = vector<int> (2*n, 0);
        this->anti_diag = vector<int> (2*n, 0);
        this->counter = 0;
        dfs(n, 0);
        
        return this->counter;
    }
    
private:
    vector<int> column;
    vector<int> main_diag;
    vector<int> anti_diag;
    int counter;
    
    void dfs(int n, int row) {
        int result = 0;
        if (row == n) {
            counter++;
            return;
        }
        
        for (int j = 0; j < n; j++) {
            bool ok = !(column[j] || main_diag[row + j] || anti_diag[row -j + n]);
            if (!ok) continue;
            
            column[j] = main_diag[row + j] = anti_diag[row -j + n] = 1;
            dfs(n, row + 1);
            column[j] = main_diag[row + j] = anti_diag[row -j + n] = 0;
        }
    }
};