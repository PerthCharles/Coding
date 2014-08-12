/*
 *  Word Ladder
 *      Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
 *
 *      Only one letter can be changed at a time
 *      Each intermediate word must exist in the dictionary
 *      For example,
 *
 *      Given:
 *      start = "hit"
 *      end = "cog"
 *      dict = ["hot","dot","dog","lot","log"]
 *      As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *      return its length 5.
 *
 *      Note:
 *      Return 0 if there is no such transformation sequence.
 *      All words have the same length.
 *      All words contain only lowercase alphabetic characters.
 */


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> current, next;
        int len = 0;
        unordered_set<string> visited;
        
        current.push(start);
        visited.insert(start);
        while(!current.empty()) {
            len++;
            while(!current.empty()) {
                string cur = current.front();
                current.pop();
                if (cur == end) return len;
                
                for (int i = 0; i < cur.size(); i++) {
                    char tmp = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == tmp) continue;
                        cur[i] = c;
                        if (visited.find(cur) == visited.end() && dict.find(cur) != dict.end()) {
                            if (cur == end) return len+1;
                            next.push(cur);
                            visited.insert(cur);
                        }
                        cur[i] = tmp;
                    }
                }
            }
            
            while(!next.empty()) {
                string tmp = next.front();
                next.pop();
                current.push(tmp);
            }
        }
        
        return 0;
    }
};