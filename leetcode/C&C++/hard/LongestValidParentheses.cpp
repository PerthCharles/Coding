/*
 *  Longest Valid Parentheses
 *      Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 *      For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 *      Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;    // the position of the last non-matched '('
        int len = 0, last = -1; // the position of the last non-matched ')'
        int result = 0;
        
        //stk.push(0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')' && stk.empty()) {
                last = i; // found a non-matched ')', therefore the begin of valid parentheses start from here
            } else if (s[i] == ')' && !stk.empty()) {
                stk.pop();
                if (stk.empty()) len = i - last;
                else len = i - stk.top();
                if (len > result) result = len;
            }
        }
        
        return result;
    }
};