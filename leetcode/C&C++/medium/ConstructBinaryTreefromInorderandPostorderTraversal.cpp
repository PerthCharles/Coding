/*
 *  Construct Binary Tree from Inorder and Postorder Traversal
 *      Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 *      Note:
 *      You may assume that duplicates do not exist in the tree.
 */

// TODO: learn more about STL in C++

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    template <typename buildit>
    TreeNode *buildTree(buildit ifrom, buildit ito, buildit pfrom, buildit pto) {
        if (ifrom == ito) return NULL;
        
        TreeNode* root = new TreeNode(*prev(pto));
        
        auto inrootpos = find(ifrom, ito, *prev(pto));
        auto leftsize = distance(ifrom, inrootpos);
        auto post_left_to = next(pfrom, leftsize);
        
        root->left = buildTree(ifrom, inrootpos, pfrom, post_left_to);
        root->right = buildTree(next(inrootpos), ito, post_left_to, prev(pto));
        
        return root;
    }
};