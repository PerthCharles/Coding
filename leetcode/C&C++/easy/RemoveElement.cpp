/*
 * Remove Element
 *      Given an array and a value, remove all instances of that value in place and return the new length.
 *
 *      The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i, len, tmp;
        
        for (i = 0, len = n; i < len; i++) {
            if (A[i] == elem) {
                while(len > 0 && A[len - 1] == elem) {
                    len--;
                }
                if (i < len) {
                    tmp = A[i];
                    A[i] = A[len-1];
                    A[len-1] = tmp;
                    len--;
                }
            }
        }
        
        return len;
    }
};