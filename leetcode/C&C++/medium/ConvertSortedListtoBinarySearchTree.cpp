/*
 *  Convert Sorted List to Binary Search Tree
 *      Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

// reference: http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len);
    }
private:
    TreeNode *sortedListToBST(ListNode *& cur, int begin, int end) {
        if (begin >= end) return NULL;
        
        int mid = begin + (end - begin)/2;
        TreeNode *left_child = sortedListToBST(cur, begin, mid);
        TreeNode *parent = new TreeNode(cur->val);
        cur = cur->next;    // this step makes sure that cur is the root node  
        parent->left = left_child;
        parent->right = sortedListToBST(cur, mid+1, end);
        
        return parent;
    }
};

// other method:
// convert list => vector array ==> binary-search-tree
