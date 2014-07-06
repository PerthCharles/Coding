/*
 * Merge Sorted Array
 *      Given two sorted integer arrays A and B, merge B into A as one sorted array.
 */


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m, j = n, k = m+n;
        
        while (i > 0 && j > 0) {
            if (A[i-1] <= B[j-1]) {
                A[k-1] = B[j-1];
                j--;
            } else {
                A[k-1] = A[i-1];
                i--;
            }
            k--;
        }
        while (j > 0) {
            A[k-1] = B[j-1];
            j--;
            k--;
        }
    }
};