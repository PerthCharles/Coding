/*
 * Remove Duplicates from Sorted List II
 *      Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 *      For example,
 *      Given 1->2->3->3->4->4->5, return 1->2->5.
 *      Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        int dup;
        
        while (cur) {
            dup = 0;
            while (cur->next && cur->val == cur->next->val) {
                dup = 1;
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if (dup) {      // Because all the node need to be deleted, prev->next is still known
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            } else {        // prev can go to the next node which will be in the last result link
                prev->next = cur;
                prev = prev->next;
                cur = prev->next;
            }
        }
        
        prev->next = NULL;  // prev->next should be NULL at the end;
        return dummy.next;
    }
};