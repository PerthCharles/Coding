/*
 * Symmetric Tree
 *      Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isMirror(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL) return true;
        else if (l == NULL || r == NULL) return false;
        else return (l->val == r->val)&&isMirror(l->left, r->right)&&isMirror(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        
        return isMirror(root->left, root->right);
    }
};