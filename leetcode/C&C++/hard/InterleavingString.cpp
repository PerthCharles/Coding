/*
 *  Interleaving String
 *      Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 *      For example,
 *      Given:
 *      s1 = "aabcc",
 *      s2 = "dbbca",
 *
 *      When s3 = "aadbbcbcac", return true.
 *      When s3 = "aadbbbaccc", return false.
 */


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        //if (s1.size() == 0) return s2 == s3;
        //if (s2.size() == 0) return s1 == s3;
        
        vector<bool> match(s2.size()+1, false);
        
        match[0] = true;
        for (int k2 = 1; k2 <= s2.size(); k2++) {
            match[k2] = (match[k2-1] && s2[k2-1] == s3[k2-1]);
        }
        
        for (int k1 = 1; k1 <= s1.size(); k1++) {
            match[0] = (match[0] && s1[k1-1] == s3[k1-1]);
            for (int k2 = 1; k2 <= s2.size(); k2++) {
                match[k2] = (s1[k1-1] == s3[k1+k2-1] && match[k2]) || (s2[k2-1] == s3[k1+k2-1] && match[k2-1]);
            }
        }
        
        return match[s2.size()];
    }
};