/*
 *  Distinct Subsequences
 *      Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 *      A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 *      Here is an example:
 *      S = "rabbbit", T = "rabbit"
 *
 *      Return 3.
 */



class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size() + 1, 0);
        
        f[0] = 1;   // if T.size() == 0, then should return 1;
        for (int i = 0; i < S.size(); i++) {
            for (int j = T.size()-1; j >= 0; j--) {
                if (S[i] == T[j]) f[j+1] += f[j];
            }
        }
        
        return f[T.size()];
    }
};