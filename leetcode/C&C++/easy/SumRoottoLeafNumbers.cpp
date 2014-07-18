/*  Sum Root to Leaf Numbers
 *      Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 *      An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 *      Find the total sum of all root-to-leaf numbers.
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
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode *root, int sum) {
        int result;
        
        if (root == NULL) return 0;
        
        result = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) return result;
        return dfs(root->left, result) + dfs(root->right, result);
    }
};