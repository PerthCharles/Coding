/*
 *  Flatten Binary Tree to Linked List
 *      Given a binary tree, flatten it to a linked list in-place.
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
    void flatten(TreeNode *root) {
        TreeNode *p, *q;
        if (root == NULL) return;
        
        p = root;
        while (p) {
            if (p->left == NULL) {
                p = p->right;
            } else {
                q = p->left;
                // morris: find the node before p->right;
                while (q && q->right) {
                    q = q->right;
                }
                q->right = p->right;
                
                p->right = p->left;
                p->left = NULL;
                
                p = p->right;
            }
        }
    }
};