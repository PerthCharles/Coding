/*
 *  Wildcard Matching
 *      Implement wildcard pattern matching with support for '?' and '*'.
 *
 *      '?' Matches any single character.
 *      '*' Matches any sequence of characters (including the empty sequence).
 *
 *      The matching should cover the entire input string (not partial).
 *
 *      The function prototype should be:
 *      bool isMatch(const char *s, const char *p)
 *
 *      Some examples:
 *      isMatch("aa","a") → false
 *      isMatch("aa","aa") → true
 *      isMatch("aaa","aa") → false
 *      isMatch("aa", "*") → true
 *      isMatch("aa", "a*") → true
 *      isMatch("ab", "?*") → true
 *      isMatch("aab", "c*a*b") → false
 */


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        
        for (str = s, ptr = p; *str != '\0';) {
            switch (*ptr) {
                case '?':
                    str++;
                    ptr++;
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while (*p == '*') p++;
                    if (*p == '\0') return true;
                    str = s, ptr = p;
                    break;
                default:
                    if (*str != *ptr) {
                        if (!star) return false;
                        s++;
                        str = s;
                        ptr = p;
                    } else {
                        str++;
                        ptr++;
                    }
            }
        }
        
        while (*ptr == '*') ptr++;
        
        return (*ptr == '\0');
    }
};