/*
 *  Search for a Range
 *  Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 *  Your algorithm's runtime complexity must be in the order of O(log n).
 *
 *  If the target is not found in the array, return [-1, -1].
 *
 *  For example,
 *  Given [5, 7, 7, 8, 8, 10] and target value 8,
 *  return [3, 4].
 */


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        
        // find the leftest one
        int from = 0, to = n, mid;
        while(from < to) {
            mid = from + (to - from)/2;
            if (target == A[mid]) {
                result[0] = mid;
            }
            
            if (target <= A[mid]) {
                to = mid;
            } else {
                from = mid + 1;
            }
        }
        
        if (result[0] == -1) {
            return result;
        } else {
            result[1] = result[0];
        }
        
        // fint the rightest one
        from = result[0] + 1; to = n;
        while (from < to) {
            mid = from + (to - from)/2;
            if (target == A[mid]) {
                result[1] = mid;
            }
            
            if (target < A[mid]) {
                to = mid;
            } else {
                from = mid + 1;
            }
        }
        
        return result;
    }
};