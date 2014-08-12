/*
 *  Longest Palindromic Substring
 *      Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

// DP
class Solution_1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool f[n][n];  // f[i][j] == true represents [i, j] is palindrome
        fill_n(&f[0][0], n*n, false);
        if (n < 2) return s;
        
        int max = 1, start = 0;
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
            for (int j = i-1; j >= 0; j--) { //  [j, i]
                f[j][i] = (s[j] == s[i] && (i-j < 2 || f[j+1][i-1])) ;
                if (f[j][i] && max < (i-j+1)) {
                    max = i-j+1;
                    start = j;
                }
            }
        }
        
        return s.substr(start, max);
    }
};

// TODO: manacher
