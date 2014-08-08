/*
 *  Copy List with Random Pointer
 *      A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 *      Return a deep copy of the list.
 */


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return head;
        for (RandomListNode *cur = head; cur != NULL;) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        
        for (RandomListNode *cur = head; cur != NULL;) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        RandomListNode dummy(-1);
        RandomListNode *h2 = &dummy;
        for (RandomListNode *cur = head; cur != NULL;) {
            h2->next = cur->next;
            cur->next = cur->next->next;
            
            h2 = h2->next;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};