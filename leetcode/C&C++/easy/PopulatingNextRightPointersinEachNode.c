/*
 * Populating Next Right Pointers in Each Node
 *      Given a binary tree
 *
 *          struct TreeLinkNode {
 *              TreeLinkNode *left;
 *              TreeLinkNode *right;
 *              TreeLinkNode *next;
 *          }
 *      
 *      Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *      Initially, all next pointers are set to NULL.
 */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root;
        
        while (cur) {
            TreeLinkNode *first = NULL;  // the first node of next level
            TreeLinkNode *prev = NULL;   // previous node on the same level;
            
            // connect nodes which in the same level with cur
            for (; cur; cur = cur->next) {
                if (!first) first = cur->left ? cur->left : cur->right;
                
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    prev = cur->right;
                }
            }
            
            // go to the next level
            cur = first;
        }
    }
};