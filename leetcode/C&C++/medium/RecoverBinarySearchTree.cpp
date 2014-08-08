/*
 *  Recover Binary Search Tree
 *      Two elements of a binary search tree (BST) are swapped by mistake.
 *
 *      Recover the tree without changing its structure.
 *
 *      Note:
 *      A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode *root) {
        // morris inorder
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        TreeNode *first = NULL, *second = NULL;
        
        while (cur) {
            if (cur->left == NULL) {
                if (prev && prev->val >= cur->val) {
                    if (first == NULL) first = prev;
                    second = cur;
                }
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *tmp = cur->left;
                while (tmp->right && tmp->right != cur) tmp = tmp->right;
                if (tmp->right == NULL) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    if (prev && prev->val >= cur->val) {
                        if (first == NULL) first = prev;
                        second = cur;
                    }
                    tmp->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        
        // swap first and second
        int tmpval = first->val;
        first->val = second->val;
        second->val = tmpval;
        
    }
};