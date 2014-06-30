/*
 * Single Number
 *      Given an array of integers, every element appears twice except for one. Find that single one.
 */


class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0, i;
        
        for (i = 0; i < n; i++) {
            result = result ^ A[i];
        }
        
        return result;
    }
};