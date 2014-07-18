/*
 *  Path Sum
 *  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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

// recursive
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) return root->val == sum;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

