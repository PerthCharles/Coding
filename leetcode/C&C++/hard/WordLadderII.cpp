/*
 *  Word Ladder II
 *      Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 *
 *      Only one letter can be changed at a time
 *      Each intermediate word must exist in the dictionary
 *      For example,
 *
 *      Given:
 *      start = "hit"
 *      end = "cog"
 *      dict = ["hot","dot","dog","lot","log"]
 *      Return
 *        [
 *            ["hit","hot","dot","dog","cog"],
 *                ["hit","hot","lot","log","cog"]
 *                  ]
 *                  Note:
 *                  All words have the same length.
 *                  All words contain only lowercase alphabetic characters.
 */


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        bool found = false;
        unordered_set<string> current, next;
        vector<vector<string> > result;
        unordered_map<string, vector<string> > search_map;
        
        
        current.insert(start);
        
        while (!current.empty() && !found) {
            for (auto it = current.begin(); it != current.end(); it++) {
                search_map[*it];
            }
            
            for (auto it = current.begin(); it != current.end(); it++) {
                string cur = *it;
                if (cur == end) found = true;
                
                char tmp;
                string changed;
                for (int i = 0; i < cur.size(); i++) {
                    changed = cur;
                    tmp = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == tmp) continue;
                        changed[i] = c;
                        if (dict.find(changed) == dict.end() && changed != end) continue;
                        if (search_map.find(changed) == search_map.end()) {
                            if (changed == end) found = true;
                            
                            search_map[cur].push_back(changed);   // cur->changed
                            next.insert(changed);
                        }
                    }
                }
            }
            
            current.clear();
            swap(current, next);
        }
        
        if (found) {
            vector<string> path;
            gen_path(search_map, path, start, end, result);
        }
        
        
        return result;
    }
private:
    void gen_path(unordered_map<string, vector<string> > &search_map, vector<string> &path,
                  const string &start, const string &end, vector<vector<string> > &result) {
        path.push_back(start);
        if (start == end) {
            result.push_back(path);
        } else if (search_map.find(start) == search_map.end()) {
            ;  // start is not in search_map
        } else {
            for (int i = 0; i < search_map[start].size(); i++) {
                gen_path(search_map, path, search_map[start][i], end, result);
            }
        }
        path.pop_back();
    }
};