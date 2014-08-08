/*
 *  Valid Palindrome
 *      Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 *      For example,
 *      "A man, a plan, a canal: Panama" is a palindrome.
 *      "race a car" is not a palindrome.
 *
 *      Note:
 *      Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 *      For the purpose of this problem, we define empty string as valid palindrome.
 */


class Solution {
public:
    bool isPalindrome(string s) {
        const int N = s.size();
        if (N == 0) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        auto first = s.begin(), last = prev(s.end());
        while (first < last) {
            if (!isalnum(*first)) first++;
            else if (!isalnum(*last)) last--;
            else if (*first != *last) return false;
            else {
                first++;
                last--;
            }
        }
        return true;
    }
};