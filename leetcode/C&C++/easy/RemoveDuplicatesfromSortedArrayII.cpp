/*
 *  Remove Duplicates from Sorted Array II
 *      Follow up for "Remove Duplicates":
 *      What if duplicates are allowed at most twice?
 *
 *      For example,
 *      Given sorted array A = [1,1,1,2,2,3],
 *
 *      Your function should return length = 5, and A is now [1,1,2,2,3].
 */


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int flag, count;
        int len, i;
        if (n <= 2) return n;
        flag = A[0];
        count = 0;
        len = 0;
        for (i = 0; i < n; i++) {
            if (A[i] == flag) {
                count++;
            } else {
                flag = A[i];
                count = 1;
            }
            
            if (count <= 2) {
                A[len++] = A[i];
            }
        }
        
        return len;
    }
};