/*
 *  Word Break II
 *      Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 *      Return all such possible sentences.
 *
 *      For example, given
 *      s = "catsanddog",
 *      dict = ["cat", "cats", "and", "sand", "dog"].
 *
 *      A solution is ["cats and dog", "cat sand dog"].
 */


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
        vector<bool> f(s.size() + 1, false);
        // "word[i][j] == true" represents [j, i) is a word and [0, j) can be separated
        vector<vector<bool> > word(s.size()+1, vector<bool>(s.size(), false));
        f[0] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (f[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    f[i] = true;
                    word[i][j] = true;
                }
            }
        }
        
        vector<string> result;
        vector<string> path;
        
        dfs(s, word, s.size(), path, result);
        return result;
    }
private:
    void dfs(string &s, vector<vector<bool> > &word, int rest_len, vector<string> &path, vector<string> &result) {
        if (rest_len == 0) {
            string tmp;
            if (path.size() != 0) {
                tmp += path[path.size()-1];
                for (int i = path.size()-2; i >= 0; i--) {
                    tmp += " " + path[i];
                }
            }
            result.push_back(tmp);
        } else {
            for (int from = 0; from < rest_len; from++) {
                if (word[rest_len][from]) {  // [from, rest_len) is a word and [0, from) can be separated
                    path.push_back(s.substr(from, rest_len - from));
                    dfs(s, word, from, path, result);  // search in [0, from)
                    path.pop_back();
                }
            }
        }
    }
};