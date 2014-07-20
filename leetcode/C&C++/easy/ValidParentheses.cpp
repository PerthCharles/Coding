/*
 *  Valid Parentheses
 *      Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *      The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */


class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        map<char, char> mapper = {{'}', '{'}, {']', '['}, {')', '('}};
        int len = s.length(), i;
        
        if (len == 0) return true;
        for (i = 0; i < len; i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                s1.push(s[i]);
            } else if (!s1.empty() && mapper[s[i]] == s1.top()) {
                s1.pop();
            } else {
                return false;
            }
        }
        
        if (s1.empty()) {
            return true;
        } else {
            return false;
        }
    }
};