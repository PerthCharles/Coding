/*
 *  Largest Rectangle in Histogram
 *      Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *      For example,
 *      Given height = [2,1,5,6,2,3],
 *      return 10.
 */


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;    // index of item in height
        height.push_back(0); // added for coner case
        int result = 0;
        
        for (int i = 0; i < height.size();) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int tmp = s.top();
                s.pop();
                // if s.empty(), then tmp is the smallest item, therefore area = height[tmp] * i;
                // if !s.empty(), then the area = length of [s.top()+1, i) * height[tmp];
                result = max(result, height[tmp] *
                             (s.empty() ? i : i - 1 - s.top()));
            }
        }
        
        return result;
    }
private:
    int max (int a, int b) {
        return a > b ? a : b;
    }
};