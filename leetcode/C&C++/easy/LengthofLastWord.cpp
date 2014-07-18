/*
 *  Length of Last Word
 *      Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 *      If the last word does not exist, return 0.
 *
 *      Note: A word is defined as a character sequence consists of non-space characters only.
 *
 *      For example, 
 *      Given s = "Hello World",
 *      return 5.
 */

// Note:
// Given s = "Hello World   ",
// also return 5!



class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s != '\0') {
            if (*s != ' ') len++;
            else if (*(s+1) != '\0' && *(s+1) != ' ') len = 0;
            
            s++;
        }
        
        return len;
    }
};