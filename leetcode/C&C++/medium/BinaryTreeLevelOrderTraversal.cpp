/*
 *  Binary Tree Level Order Traversal
 *      Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        queue<TreeNode *> cur, next;
        TreeNode * p;
        if (root == NULL) return result;
        cur.push(root);
        
        while (!cur.empty()) {
            level.erase(level.begin(), level.end());  // clear
            while (!cur.empty()) {
                p = cur.front();
                cur.pop();
                
                level.push_back(p->val);
                if (p->left) next.push(p->left);
                if (p->right) next.push(p->right);
            }
            result.push_back(level);
            while (!next.empty()) {
                p = next.front();
                next.pop();
                cur.push(p);
            }
        }
        
        return result;
    }
};