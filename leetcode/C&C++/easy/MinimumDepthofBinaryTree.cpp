/*
 *  Minimum Depth of Binary Tree
 *  Given a binary tree, find its minimum depth.
 *
 *  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

// Non-recursive with two queue.
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        
        queue<TreeNode *> cur, nxt;
        TreeNode *p;
        int result = 0;
        
        cur.push(root);
        while (!cur.empty()) {
            result++;
            while (!cur.empty()) {
                p = cur.front();
                cur.pop();
                if (p->left == NULL && p->right == NULL) {
                    return result;
                }
                if (p->left) {
                    nxt.push(p->left);
                }
                if (p->right) {
                    nxt.push(p->right);
                }
            }
            
            // swap cur and nxt;
            while (!nxt.empty()) {
                p = nxt.front();
                nxt.pop();
                cur.push(p);
            }
        }
        
        return result;
    }
};