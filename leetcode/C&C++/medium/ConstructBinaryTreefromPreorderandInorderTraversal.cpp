/*
 *  Construct Binary Tree from Preorder and Inorder Traversal
 *      Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 *      Note:
 *      You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    template<typename InputIterator>
    TreeNode *buildTree(InputIterator pfrom, InputIterator pto, InputIterator ifrom, InputIterator ito) {
        if (pfrom >= pto) return NULL;
        
        TreeNode *root = new TreeNode(*pfrom);
        auto inrootpos = find(ifrom, ito, *pfrom);
        auto leftsize = distance(ifrom, inrootpos);
        root->left = buildTree(next(pfrom), next(pfrom, leftsize + 1), ifrom, next(ifrom, leftsize));
        root->right = buildTree(next(pfrom, leftsize+1), pto, next(inrootpos), ito);
        return root;
    }
};