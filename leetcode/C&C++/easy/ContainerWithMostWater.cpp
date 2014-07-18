/*
 *  Container With Most Water
 *  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 *  Note: You may not slant the container.
 */


class Solution {
public:
    int maxArea(vector<int> &height) {
        // If left < right, find another bigger left; else find another bigger right
        int begin = 0, end = height.size() - 1;
        int result = -1, tmp, shorter;
        
        while (begin < end) {
            shorter = height[begin] <= height[end] ? height[begin] : height[end];
            tmp = (end - begin)*shorter;
            result = tmp > result ? tmp : result;
            if (height[begin] <= height[end]) {
                while (begin < end && height[begin] <= shorter) {
                    begin++;
                }
            } else {
                while (begin < end && height[end] <= shorter) {
                    end--;
                }
            }
        }
        
        return result;
    }
};