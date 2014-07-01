/*
 * Single Number II
 *      Given an array of integers, every element appears three times except for one. Find that single one.
 *
 *      Note:
 *      Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */


class Solution {
public:
    int singleNumber(int A[], int n) {
        int sum_bits[32] = {0};
        int i, j, flag, result;
        int size = sizeof(int);
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < size*8; j++) {
                flag = A[i] & (1 << j);
                if (flag) {
                    sum_bits[j] = (sum_bits[j] + 1)%3;
                }
            }
        }
        
        result = 0;
        for (j = size*8 - 1; j >= 0; j--) {
            result = (result << 1) | sum_bits[j];
        }
        
        return result;
    }
};
