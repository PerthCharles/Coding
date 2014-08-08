/*
 *  Scramble String
 *      https://oj.leetcode.com/problems/scramble-string/
 */


class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Dynamic Programming
        const int N = s1.size();
        if (s2.size() != N) return false;
        if (N == 0) return true;
        
        // f[len][i][j] represents that whether
        // sub1[i, i+len) is scramble with sub2[j, j+len).
        bool f[N+1][N][N];
        fill_n(&f[0][0][0], N*N*(N+1), false);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                f[0][i][j] = true;
                f[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len <= N; i++) {
                for (int j = 0; j + len <= N; j++) {
                    for (int k = 1; k < len; k++) {
                        if ((f[k][i][j] && f[len-k][i+k][j+k])
                            || (f[k][i][j+len-k] && f[len-k][i+k][j])) {
                            f[len][i][j] = true;
                            break;
                        }
                    }
                }
                
            }
        }
        
        return f[N][0][0];
    }
};