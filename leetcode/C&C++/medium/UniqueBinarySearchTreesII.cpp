/*
 *  Unique Binary Search Trees II
 *      Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode *> generateTrees(int begin, int end) {
        vector<TreeNode *> result;
        if (begin > end) {
            result.push_back(NULL);
            return result;
        }
        
        for (int root = begin; root <= end; root++) {
            vector<TreeNode *> left = generateTrees(begin, root - 1);
            vector<TreeNode *> right = generateTrees(root + 1, end);
            for (auto i : left) {
                for (auto j : right) {
                    TreeNode *cur = new TreeNode(root);
                    cur->left = i;
                    cur->right = j;
                    result.push_back(cur);
                }
            }
        }
        
        return result;
    }
};