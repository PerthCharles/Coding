/*
 *  Palindrome Partitioning II
 *      Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 *      Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *      For example, given s = "aab",
 *      Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */


class Solution {
public:
    int minCut(string s) {
        const int N = s.length();
        if (N < 2) return 0;
        
        int cuts[N]; // cuts[i] is minmum cuts for [0, i]
        bool palin[N][N];
        for (int i = 0; i < N; i++) {
            cuts[i] = i;   // worst case
            for (int j = 0; j < N; j++) {
                palin[i][j] = false;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i; j >= 0; j--) {
                // if [j, i] is palindrome
                if ((s[j] == s[i]) && (i - j < 2 || palin[j+1][i-1])) {
                    palin[j][i] = true;
                    if (j == 0) cuts[i] = 0;
                    else cuts[i] = min(cuts[i], cuts[j-1] + 1);
                }
            }
        }
        
        return cuts[N-1];
    }
    
private:
    int min (int a, int b) {
        return a <= b ? a : b;
    }
};