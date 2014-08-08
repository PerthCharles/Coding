/*
 *  Reorder List
 *      Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *      reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 *      You must do this in-place without altering the nodes' values.
 *
 *      For example,
 *      Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        int len = 0;
        ListNode *p = head, *h2;
        while (p) {
            len++;
            p = p->next;
        }
        if (len < 3) return;
        
        // find the head of inserted nodes
        p = head;
        for (int i = 0; i < len/2; i++) {
            p = p->next;
        }
        h2 = p->next;
        p->next = NULL;
        
        // swap list of h2
        ListNode dummy(-1);
        dummy.next = h2;
        ListNode *cur = h2;
        while (cur->next) {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = dummy.next;
            dummy.next = nxt;
        }
        
        // merge two list: head and h2
        cur = dummy.next;  // node in h2
        p = head;
        while (cur) {
            dummy.next = cur->next;
            cur->next = p->next;
            p->next = cur;
            
            p = cur->next;
            cur = dummy.next;
        }
    }
};