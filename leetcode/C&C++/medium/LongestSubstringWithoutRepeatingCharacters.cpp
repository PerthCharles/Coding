/*
 *  Longest Substring Without Repeating Characters
 *      Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();
        if (N < 2) return N;
        
        int start = 0, result = 0;
        int flag[256];
        fill_n(&flag[0], 256, -1);
        
        for (int i = 0; i < N; i++) {
            if (flag[s[i]] >= start) {
                start = flag[s[i]] + 1;
            }
            flag[s[i]] = i;
            result = max(result, i - start + 1);
        }
        
        return result;
    }
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};