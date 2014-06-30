/*
 * Maximum Depth of Binary Tree
 *      Given a binary tree, find its maximum depth.
 *      The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
// Recursive
class Solution_1 {
public:
    int maxDepth(TreeNode *root) {
        int left, right;
        if (root == NULL) return 0;
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        return left >= right ? (left + 1):(right + 1);
    }
};

// Non-recursive
class Solution_2 {
public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> current, next;
        TreeNode *node;
        int result = 0;
        
        if (root == NULL) return result;
        current.push(root);
        
        while(!current.empty()) {
            result++;
            while(!current.empty()) {
                node = current.front();
                if (node->left) next.push(node->left);
                if (node->right) next.push(node->right);
                current.pop();
            }
            // swap next and current;
            while(!next.empty()) {
                node = next.front();
                current.push(node);
                next.pop();
            }
        }
        
        return result;
    }
};
