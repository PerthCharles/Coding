/*
 *  Populating Next Right Pointers in Each Node II
 *      Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 *      What if the given tree could be any binary tree? Would your previous solution still work?
 *
 *      Note:
 *
 *      You may only use constant extra space.
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
        TreeLinkNode *first;  // first node in the same level
        TreeLinkNode *prev;   // previous node
        TreeLinkNode *cur;
        
        cur = root;
        while (cur) {
            first = NULL;
            prev = NULL;
            while (cur) {
                if (!first) first = cur->left ? cur->left : cur->right;
                
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            
            cur = first; // goto the next level
        }
    }
};