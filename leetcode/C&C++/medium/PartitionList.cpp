/*
 *  Partition List
 *      Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 *      You should preserve the original relative order of the nodes in each of the two partitions.
 *
 *      For example,
 *      Given 1->4->3->2->5->2 and x = 3,
 *      return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *left = &dummy;  // point to the last node less than 'x'
        ListNode *prev, *cur;
        prev = &dummy;
        cur = head;
        
        while (cur) {
            if (cur->val >= x) {
                prev = cur;
                cur = cur->next;
            } else {
                if (prev == left) {  // all the previous is less than 'x'
                    left = left->next;
                    prev = prev->next;
                    cur = prev->next;
                } else {
                    prev->next = cur->next;
                    cur->next = left->next;
                    left->next = cur;
                    
                    cur = prev->next;
                    left = left->next;
                }
            }
        }
        
        return dummy.next;
    }
};