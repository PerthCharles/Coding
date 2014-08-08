/*
 *  Edit Distance
 *      Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 *      You have the following 3 operations permitted on a word:
 *
 *      a) Insert a character
 *      b) Delete a character
 *      c) Replace a character
 */


class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.length();
        const int len2 = word2.length();
        
        if (len1 * len2 == 0) return len1 + len2;
        
        int dis[len1 + 1][len2 + 1];
        
        for (int j = 0; j <= len2; j++) {
            dis[0][j] = j;
        }
        
        for (int i = 1; i <= len1; i++) {
            dis[i][0] = i;
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dis[i][j] = dis[i-1][j-1];
                } else {
                    dis[i][j] = min(dis[i-1][j-1], min(dis[i-1][j], dis[i][j-1])) + 1;
                }
            }
        }
        
        return dis[len1][len2];
    }
private:
    int min(int a, int b) {
        return a <= b ? a : b;
    }
};