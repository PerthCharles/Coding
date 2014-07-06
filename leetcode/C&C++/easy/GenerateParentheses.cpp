/*
 * Generate Parentheses
 *      Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 *      For example, given n = 3, a solution set is:
 *
 *      "((()))", "(()())", "(())()", "()(())", "()()()"
 */


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string>(1, "()");
        
        vector<string> result;
        vector<string> inner, outer;
        string s1, s2;
        int i, j, k, len1, len2;
        
        for (i = 0; i < n; i++) {
            inner = generateParenthesis(i);
            outer = generateParenthesis(n-i-1);
            len1 = inner.size();
            len2 = outer.size();
            
            for(j = 0; j < len1; j++) {
                for (k = 0; k < len2; k++) {
                    result.push_back("(" + inner[j] + ")" + outer[k]);
                }
            }
        }
        
        return result;
    }
};