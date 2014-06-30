/*
 * Binary Tree Inorder Traversal
 *      Given a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector< int > result, left, right;
        int i;
        if (root == NULL) return result;
        left = inorderTraversal(root->left);
        right = inorderTraversal(root->right);
        for (i = 0; i < left.size(); i++) {
            result.push_back(left[i]);
        }
        result.push_back(root->val);
        for (i = 0; i < right.size(); i++) {
            result.push_back(right[i]);
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
// Non-recursive with stack
class Solution_2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        vector<int> result;
        stack<TreeNode *> s;
        
        while (!s.empty() || p != NULL) {
            if (p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
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
class Solution_3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *p = root, *tmp;
        vector<int> result;
        stack<TreeNode *> s;
        
        while (p != NULL) {
            if (p->left == NULL) {
                result.push_back(p->val);
                p = p->right;
            } else {
                tmp = p->left;
                while (tmp->right != NULL && tmp->right != p) {
                    tmp = tmp->right;
                }
                
                if (tmp->right == p) {
                    result.push_back(p->val);
                    tmp->right = NULL;
                    p = p->right;
                } else {
                    tmp->right = p;
                    p = p->left;
                }
            }
        }
        
        return result;
    }
};