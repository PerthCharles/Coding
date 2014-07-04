/*
 * Convert Sorted Array to Binary Search Tree
 *      Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return BinarySearchStyleConvert(num, 0, n);
    }
    
    TreeNode *BinarySearchStyleConvert(vector<int> &num, int from, int to) {
        if (from >= to) return NULL;
        
        int mid = (from + to)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = BinarySearchStyleConvert(num, from, mid);
        root->right = BinarySearchStyleConvert(num, mid+1, to);
        
        return root;
    }
};