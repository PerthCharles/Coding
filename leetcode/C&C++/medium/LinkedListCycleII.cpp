/*
 * Linked List Cycle II
 *      Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 *      Follow up:
 *      Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p, *q;
        p = q = head;
        if (head == NULL) return NULL;
        
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return q;
            }
        }
        
        return NULL;
    }
};