/*
 * Letter Combinations of a Phone Number
 *      Given a digit string, return all possible letter combinations that the number could represent.
 *
 *      A mapping of digit to letters (just like on the telephone buttons) is given below.
 *      vector<string> keyboard{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        dfs(digits, 0, "", result);
        return result;
    }
private:
    vector<string> keyboard{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int cur, string path, vector<string> &result) {
        if (cur == digits.length()) {
            result.push_back(path);
            return;
        }
        
        // C style
        /*
         if (keyboard[digits[cur] - '0'].length() == 0) {    // digits[cur] == '1'
         dfs(digits, cur+1, path, result);
         } else {
         for (int i = 0; i < keyboard[digits[cur] - '0'].length(); i++) {
         dfs(digits, cur+1, path+keyboard[digits[cur] - '0'][i], result);
         }
         }
         */
        
        // C++ style
        for (auto c : keyboard[digits[cur] - '0']) {
            dfs(digits, cur+1, path + c, result);
        }
    }
};