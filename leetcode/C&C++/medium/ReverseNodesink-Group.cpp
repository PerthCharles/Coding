/*
 *  Reverse Nodes in k-Group
 *      Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 *      If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 *      You may not alter the values in the nodes, only nodes itself may be changed.
 *
 *      Only constant memory is allowed.
 *
 *      For example,
 *      Given this linked list: 1->2->3->4->5
 *
 *      For k = 2, you should return: 2->1->4->3->5
 *
 *      For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        if (k < 2) return head;
        
        ListNode *cur = head, *nxt;
        ListNode *nextGroup = &dummy;
        head = &dummy;
        for (int i = 0; i < k && nextGroup; i++) {
            nextGroup = nextGroup->next;
        }
        while (nextGroup) {
            // swap k nodes
            for (int i = 1; i < k; i++) {
                nxt = cur->next;
                cur->next = nxt->next;
                nxt->next = head->next;
                head->next = nxt;
            }
            
            head = nextGroup = cur;
            cur = cur->next;
            for (int i = 0; i < k && nextGroup; i++) {
                nextGroup = nextGroup->next;
            }
        }
        
        return dummy.next;
    }
};