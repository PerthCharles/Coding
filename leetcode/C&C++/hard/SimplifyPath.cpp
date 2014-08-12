/*
 *  Simplify Path
 *      Given an absolute path for a file (Unix-style), simplify it.
 *
 *      For example,
 *      path = "/home/", => "/home"
 *      path = "/a/./b/../../c/", => "/c"
 *      click to show corner cases.
 *
 *      Corner Cases:
 *      Did you consider the case where path = "/../"?
 *      In this case, you should return "/".
 *      Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *      In this case, you should ignore redundant slashes and return "/home/foo".
 */


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> result;
        string folder;
        if (path.size() == 0) return path;
        
        //result.push_back("/");
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (folder.size() == 0 || folder == ".") {
                    folder = "";
                } else if (folder == "..") {
                    if (result.size()) result.pop_back();
                    folder = "";
                } else {
                    result.push_back(folder);
                    folder = "";
                }
            } else {
                folder += path[i];
            }
        }
        
        if (folder.size() == 0 || folder == ".") {
            ;
        } else if (folder == "..") {
            if (result.size()) result.pop_back();
        } else {
            result.push_back(folder);
        }
        
        string s_path;
        for (int i = 0; i < result.size(); i++) {
            s_path += "/";
            s_path += result[i];
        }
        
        if (s_path.size() == 0) s_path = "/";
        return s_path;
    }
};