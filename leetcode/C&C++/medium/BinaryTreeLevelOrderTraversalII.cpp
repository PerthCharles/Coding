/*
 *  Binary Tree Level Order Traversal II 
 *      Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        traverse(root, 1, result);
        reverse(result.begin(), result.end());
        
        return result;
    }
private:
    void traverse(TreeNode *root, int level, vector<vector<int> > &result) {
        if (root == NULL) return;
        if (level > result.size()) {
            result.push_back(vector<int> ());
        }
        
        result[level-1].push_back(root->val);
        traverse(root->left, level + 1, result);
        traverse(root->right, level + 1, result);
    }
};