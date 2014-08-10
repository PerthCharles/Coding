/*
 *  Restore IP Addresses
 *      Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 *      For example:
 *      Given "25525511135",
 *
 *      return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(s, 0, 0, ip, result);
        return result;
    }
    
private:
    void dfs(string &s, int from, int field_id, string ip, vector<string> &result) {
        if (field_id == 4 && from == s.size()) {
            ip.resize(ip.size()-1);
            result.push_back(ip);
            return;
        }
        
        if (s.size() - from > (4 - field_id) * 3) return;  // too many
        if (s.size() - from < (4 - field_id))     return;  // too lest
        
        int num = 0;
        for (int i = from; i < from+3; i++) {
            num = num*10 + (s[i] - '0');
            if (num <= 255) {
                ip += s[i];
                dfs(s, i+1, field_id+1, ip + '.', result);
                //ip.resize(ip.size()-1);
            }
            if (num == 0) break; // s[i] is '0', therefore stop trying
        }
    }
};