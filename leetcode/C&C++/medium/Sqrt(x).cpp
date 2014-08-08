/*
 *  Sqrt(x)
 *      Implement int sqrt(int x).
 *
 *      Compute and return the square root of x.
 */


class Solution {
public:
    int sqrt(int x) {
        if (x < 2) return x;
        int from = 1, to = x/2+1, mid, last_mid;
        
        while (from < to) {
            mid = from + (to - from)/2;
            if (x/mid > mid) {
                from = mid+1;
                last_mid = mid;
            } else if (x/mid < mid) {
                to = mid;
            } else {
                return mid;
            }
        }
        
        return last_mid;
    }
};