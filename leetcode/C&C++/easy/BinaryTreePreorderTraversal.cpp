/*
 * Binary Tree Preorder Traversal
 *      Given a binary tree, return the preorder traversal of its nodes' values.
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
// Non-recursive with stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *p;
        vector<int> result;
        stack<TreeNode *> s;
        
        p = root;
        if (p != NULL) s.push(p);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right != NULL) s.push(p->right);
            if (p->left != NULL) s.push(p->left);
        }
        return result;
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Morris algorithm
//     Morris algorithm will go to the left sub-tree twice:
//     At the first time, the index haven't been setup yet;
//     At the second time, the whole left sub-tree have been traversed and the index needs to be deleted.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur, *tmp;
        
        cur = root;
        while(cur != NULL) {
            if (cur->left == NULL) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                tmp = cur->left;
                while (tmp->right != NULL && tmp->right != cur) {
                    tmp = tmp->right;   // find the 'righttest' sub-leaf
                }
                
                if (tmp->right == NULL) {
                    result.push_back(cur->val);
                    tmp->right = cur;
                    cur = cur->left;
                } else {  // the whole left sub-tree have been traversed
                    tmp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        return result;
    }
};
