/*
 * Swap Nodes in Pairs 
 *      Given a linked list, swap every two adjacent nodes and return its head.
 *
 *      For example,
 *      Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *      Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *p, *q, *left, *h, *prev = NULL;
        h = left = head;
        while (left && left->next) {
            if (left == head) h = left->next;
            p = left;
            q = left->next;
            left = left->next->next;
            
            p->next = q->next;
            q->next = p;
            if (prev) {
                prev->next = q;
            }
            prev = p;
        }
        return h;
    }
};
