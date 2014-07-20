/*
 *  Validate Binary Search Tree
 *      Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 *      Assume a BST is defined as follows:
 *
 *      The left subtree of a node contains only nodes with keys less than the node's key.
 *      The right subtree of a node contains only nodes with keys greater than the node's key.
 *      Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        // Use LLONG_MIN and LLONG_MAX
        //to avoid bug that there is node with INT_MIN or INT_MAX
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValid(TreeNode *root, long long left, long long right) {
        if (root == NULL) return true;
        if (root->val >= right || root->val <= left) {
            return false;
        }
        
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
};