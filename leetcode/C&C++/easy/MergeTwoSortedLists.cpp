/*
 * Merge Two Sorted Lists 
 *      Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3, *p, *q, *r;
        l3 = new ListNode(0);
        p = l1;
        q = l2;
        r = l3;
        
        while (p && q) {
            if (p->val <= q->val) {
                r->next = p;
                r = p;
                p = p->next;
            } else {
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        while (p) {
            r->next = p;
            r = p;
            p = p->next;
        }
        while (q) {
            r->next = q;
            r = q;
            q = q->next;
        }
        
        return l3->next;
    }
};