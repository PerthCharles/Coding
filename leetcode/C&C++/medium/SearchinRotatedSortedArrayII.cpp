/*
 *  Search in Rotated Sorted Array II
 *      Follow up for "Search in Rotated Sorted Array":
 *      What if duplicates are allowed?
 *
 *      Would this affect the run-time complexity? How and why?
 *
 *      Write a function to determine if a given target is in the array.
 */


class Solution {
public:
    bool search(int A[], int n, int target) {
        int from = 0, to = n, mid;
        
        while (from < to) {
            mid = from + (to - from)/2;
            if (target == A[mid]) return true;
            if (target == A[from]) return true;
            if (A[mid] > A[from]) {
                if (target > A[mid] || target < A[from]) {
                    from = mid + 1;
                } else {
                    to = mid;
                }
            } else if (A[mid] < A[from]) {
                if (target < A[mid] || target > A[from]) {
                    to = mid;
                } else {
                    from = mid + 1;
                }
            } else {
                from = from + 1;
            }
        }
        
        return false;
    }
};