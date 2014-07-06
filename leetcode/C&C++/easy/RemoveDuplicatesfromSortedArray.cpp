/*
 * Remove Duplicates from Sorted Array
 *      Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 *      Do not allocate extra space for another array, you must do this in place with constant memory.
 */


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;
        if (n <= 1) return n;
        
        for (i = 0, j = 1; j < n; j++) {
            if (A[j] != A[i]) {
                i++;
                A[i] = A[j];
            }
        }
        
        return i+1;
    }
};