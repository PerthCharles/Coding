/*
 * Remove Nth Node From End of List
 *      Given a linked list, remove the nth node from the end of list and return its head.
 *
 *      For example,
 *
 *         Given linked list: 1->2->3->4->5, and n = 2.
 *
 *            After removing the second node from the end, the linked list becomes 1->2->3->5.
 *            Note:
 *            Given n will always be valid.
 *            Try to do this in one pass.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;
        ListNode tmp(0);  // Notice the way to declare new node
        tmp.next = head;
        p = q = &tmp;
        int i;
        
        // move q by n steps
        for (i = 0; i < n; i++) {
            q = q->next;
        }
        // find the node *before* the node to remove
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        
        q = p->next;
        p->next = q->next;
        free(q);
        
        return tmp.next;
    }
};