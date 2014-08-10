/*
 *  Merge k Sorted Lists
 *      Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// divide-and-conquer
class Solution_1 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKlists(lists, 0, lists.size());
    }
private:
    ListNode *mergeKlists(vector<ListNode *> &lists, int from, int to) {
        ListNode *l1, *l2;
        
        if (to - from == 0) return NULL;
        if (to - from == 1) return lists[from];
        
        if (to - from > 2) {
            int mid = from + (to - from)/2;
            l1 = mergeKlists(lists, from, mid);
            l2 = mergeKlists(lists, mid, to);
        } else {  // only two lists
            l1 = lists[from];
            l2 = lists[to-1];
        }
        
        // merge l1 and l2;
        ListNode dummy(-1);
        for (ListNode *cur = &dummy; l1 || l2; cur = cur->next) {
            int v1 = l1 == NULL ? INT_MAX : l1->val;
            int v2 = l2 == NULL ? INT_MAX : l2->val;
            if (v1 <= v2) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
        }
        
        return dummy.next;
    }
};

// TODO： k-min-heap