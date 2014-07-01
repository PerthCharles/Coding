/*
 * Search Insert Position
 *      Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 *      You may assume no duplicates in the array.
 */


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin, middle, end;
        begin = 0;
        end = n;
        middle = (begin + end)/2;
        while (begin < end && A[middle] != target) {
            if (A[middle] < target) {
                begin = middle + 1;
                middle = (begin + end)/2;
            } else {
                end = middle;
                middle = (begin + end)/2;
            }
        }
        return middle;
    }
};