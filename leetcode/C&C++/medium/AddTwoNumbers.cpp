/*
 *  Add Two Numbers
 *      You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 *      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *      Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode dummy(-1);
        int carry = 0, sum = 0;
        ListNode *p = l1, *q = l2, *r = &dummy;
        
        while (p && q) {
            sum = (carry + p->val + q->val) % 10;
            carry = (carry + p->val + q->val) / 10;
            r->next = new ListNode(sum);
            r = r->next;
            p = p->next;
            q = q->next;
        }
        while (p) {
            sum= (carry + p->val) % 10;
            carry = (carry + p->val) /10;
            r->next = new ListNode(sum);
            r = r->next;
            p = p->next;
        }
        while (q) {
            sum= (carry + q->val) % 10;
            carry = (carry + q->val) /10;
            r->next = new ListNode(sum);
            r = r->next;
            q = q->next;
        }
        if (carry > 0) {
            r->next = new ListNode(carry);
            r = r->next;
        }
        r->next = NULL;
        return dummy.next;
    }
};