/*
 *  Trapping Rain Water
 *      Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 *      For example, 
 *      Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */


// Note: for each pillar, the water it can hold(above it) is: MAX(left_heighest, right_heightest) - height

class Solution {
public:
    int trap(int A[], int n) {
        int i, sum = 0;
        int *max_left = new int[n]();
        int *max_right = new int[n]();
        
        // find max_left, max_right for each pillar
        for (i = 1; i < n-1; i++) {
            max_left[i] = max(max_left[i-1], A[i-1]);
            max_right[n-i-1] = max(max_right[n-i], A[n-i]);
        }
        
        for (i = 1; i < n-1; i++) {
            sum += max( min(max_left[i], max_right[i]) - A[i], 0);
        }
        
        return sum;
    }
    
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a <= b ? a : b;
    }
};