/*
 * Path Sum
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > result, subresult;
        
        findpath(root, path, result, sum);
        return result;
    }
private:
    void findpath(TreeNode *root, vector<int> &path, vector<vector<int> > &result, int sum) {
        if (root == NULL) return;
        
        path.push_back(root->val);  // add current node to path
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            result.push_back(path);
        }
        
        findpath(root->left, path, result, sum - root->val);
        findpath(root->right, path, result, sum - root->val);
        
        path.pop_back();  // delete curent node from path
    }
};