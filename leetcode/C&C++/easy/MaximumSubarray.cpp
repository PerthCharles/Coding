/*
 * Maximum Subarray
 *      Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 */


class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = INT_MIN, tmp = 0, i;
        
        for (i = 0; i < n; i++) {
            tmp = max(tmp + A[i], A[i]);
            result = max(result, tmp);
        }
        
        return result;
    }
private:
    int max(int a, int b) {
        return a >= b ? a: b;
    }
};