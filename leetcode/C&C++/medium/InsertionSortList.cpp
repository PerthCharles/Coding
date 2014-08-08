/*
 *  Insertion Sort List
 *      Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        
        if (head == NULL) return head;
        
        ListNode *prev = head;
        ListNode *cur = head->next;
        ListNode *insrt;   // the cur node should insert after this node
        
        while (cur) {
            insrt = &dummy;
            while (cur->val > insrt->next->val) insrt = insrt->next;
            
            if (insrt != prev) {
                prev->next = cur->next;
                cur->next = insrt->next;
                insrt->next = cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
