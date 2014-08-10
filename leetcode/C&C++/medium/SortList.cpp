/*
 *  Sort List
 *      Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        // merge-sort
        ListNode *p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        if (len < 2) return head;
        
        p = head;
        ListNode *h2;
        for (int i = 0; i < len/2 - 1; i++) {
            p = p->next;
        }
        h2 = p->next;
        p->next = NULL;
        
        // sort
        head = sortList(head);
        h2 = sortList(h2);
        
        // merge
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        for (ListNode *p = head, *q = h2; p || q; cur = cur->next) {
            int val1 = p == NULL ? INT_MAX : p->val;
            int val2 = q == NULL ? INT_MAX : q->val;
            
            if (val1 <= val2) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
        }
        
        return dummy.next;
    }
};