/*
 *  Palindrome Partitioning
 *      Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 *      Return all possible palindrome partitioning of s.
 *
 *      For example, given s = "aab",
 *      Return
 *
 *        [
 *            ["aa","b"],
 *            ["a","a","b"]
 *        ]
 */


// recursive
class Solution_1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        if (s.size() == 0) return result;
        
        dfs(s, result, path, 0, 1);
        return result;
    }
    
private:
    void dfs(string &s, vector<vector<string> > &result, vector<string> &path, int from, int to) {
        if (to == s.size()) {
            if (ispalindrome(s, from, to)) {
                path.push_back(s.substr(from, to - from));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        // don't cut
        dfs(s, result, path, from, to+1);
        // cut
        if (ispalindrome(s, from, to)) {
            path.push_back(s.substr(from, to - from));
            dfs(s, result, path, to, to+1);
            path.pop_back();
        }
    }
    
    bool ispalindrome(string &s, int from, int to) {
        while (s[from] == s[to-1] && from < to) {
            from++;
            to--;
        }
        return from >= to;
    }
};


