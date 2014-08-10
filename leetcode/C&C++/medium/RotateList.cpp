/*
 *  Rotate List
 *      Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 *      For example:
 *      Given 1->2->3->4->5->NULL and k = 2,
 *      return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        int len = 0;
        ListNode *cur = head, *new_head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        k = k % len;    // Lookout
        if (k == 0) return head;
        // find the node pointer to right-k-th node
        cur = &dummy;
        for (int i = 0; i < len - k; i++) {
            cur = cur->next;
        }
        new_head = cur->next;
        cur->next = NULL;
        dummy.next = new_head;
        // go to the last node of the original list
        while (new_head->next) {
            new_head = new_head->next;
        }
        new_head->next = head;
        
        return dummy.next;
    }
};