/*
 *  Binary Tree Zigzag Level Order Traversal
 *      Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        stack<TreeNode *> s;
        queue<TreeNode *> tmp;
        vector<int> level;
        bool left_to_right = true;
        if (root == NULL) return result;
        
        s.push(root);
        TreeNode *cur;
        
        while (!s.empty()) {
            while (!s.empty()) {
                cur = s.top();
                if (left_to_right) {
                    // left then right
                    if (cur->left) tmp.push(cur->left);
                    if (cur->right) tmp.push(cur->right);
                } else {
                    // right then left
                    if (cur->right) tmp.push(cur->right);
                    if (cur->left) tmp.push(cur->left);
                }
                s.pop();
                level.push_back(cur->val);
            }
            result.push_back(level);
            level.clear();
            
            // goto the next level
            while (!tmp.empty()) {
                cur = tmp.front();
                tmp.pop();
                s.push(cur);
            }
            left_to_right = !left_to_right;
        }
        
        return result;
    }
};