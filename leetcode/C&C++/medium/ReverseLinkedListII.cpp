/*
 *  Reverse Linked List II 
 *      Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 *      For example:
 *      Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 *      return 1->4->3->2->5->NULL.
 *
 *      Note:
 *      Given m, n satisfy the following condition:
 *      1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;   // p will pointer to the (m-1)th node
        
        for (int i = 0; i < m-1; i++) p = p->next;
        
        ListNode *q = p->next;
        for (int i = 0; i < n-m; i++) {
            ListNode *cur = q->next;
            q->next = cur->next;
            cur->next = p->next;   // insert current node after p
            p->next = cur;
        }
        
        return dummy.next;
    }
};