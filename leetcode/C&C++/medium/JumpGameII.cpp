/*
 *  Jump Game II
 *      Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 *      Each element in the array represents your maximum jump length at that position.
 *
 *      Your goal is to reach the last index in the minimum number of jumps.
 *
 *      For example:
 *      Given array A = [2,3,1,1,4]
 *
 *      The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */


// reference: http://blog.csdn.net/linhuanmars/article/details/21356187

class Solution {
public:
    int jump(int A[], int n) {
        int last = 0;  // the farest position can be reached by step
        int cur = 0;   // the farest position can be reached by step+1
        int i, result = 0, farest;
        
        for (i = 0; i < n; i++) {
            if (i > last) {
                result++;
                last = cur;
            }
            farest = A[i] + i;
            cur = farest > cur ? farest : cur;
        }
        
        return result;
    }
};