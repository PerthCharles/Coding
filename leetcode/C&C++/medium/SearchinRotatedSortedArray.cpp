/* 
 *  Search in Rotated Sorted Array
 *      Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 *      (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 *      You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 *      You may assume no duplicate exists in the array.
 */


class Solution {
public:
    int search(int A[], int n, int target) {
        int from = 0, to = n, mid;
        
        if (n == 0) return -1;
        while (from < to) {
            mid = from + (to - from) / 2;
            if (target == A[mid]) return mid;
            if (target == A[from]) return from;
            
            if (A[mid] > A[from]) {  // mid is in the first sorted slice
                if (target > A[mid] || target < A[from]) {
                    from = mid + 1;
                } else {
                    to = mid;
                }
            } else {                 // mid is in the second sorted slice
                if (target > A[from] || target < A[mid]) {
                    to = mid;
                } else {
                    from = mid + 1;
                }
            }
        }
        
        return -1;
    }
};