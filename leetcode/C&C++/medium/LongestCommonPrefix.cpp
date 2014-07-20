/*
 *  Longest Common Prefix
 *      Write a function to find the longest common prefix string amongst an array of strings.
 */


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;
        vector<char> prefix;
        if (strs.size() == 0) return result;
        if (strs.size() == 1) return strs[0];
        int len = strs[0].length(); // length of prefix;
        int i, j;
        int nums = strs.size();  // numbers of strings
        
        for (i = 0; i < len; i++) {
            prefix.push_back(strs[0][i]);
        }
        
        for (i = 1; i < nums; i++) {
            int len2 = strs[i].length();
            for (j = 0; j < len2 && j < len; j++) {
                if (strs[i][j] != prefix[j]) {
                    break;
                }
            }
            len = j;
            if (len == 0) return result;
        }
        
        for (i = 0; i < len; i++) {
            result += prefix[i];
        }
        return result;
    }
};