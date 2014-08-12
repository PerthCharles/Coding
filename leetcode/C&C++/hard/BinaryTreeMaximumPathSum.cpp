/*
 *  Binary Tree Maximum Path Sum
 *      Given a binary tree, find the maximum path sum.
 *
 *      The path may start and end at any node in the tree.
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
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        
        dfs(root, result);
        return result;
    }
private:
    // return value represents the maximum sum path which starts from root
    int dfs(TreeNode *root, int &result) {
        if (root == NULL) return 0;
        int l = dfs(root->left, result);
        int r = dfs(root->right, result);
        int sum = root->val;
        
        sum += max(max(l, r), 0);
        result = max(result,  root->val + max(l, 0) + max(r, 0));
        
        return sum;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
};