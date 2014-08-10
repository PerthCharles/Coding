/*
 *  Maximal Rectangle
 *      Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> height;
        int result = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int tmp = matrix[i][j] - '0';
                if (i == 0) {
                    height.push_back(tmp);
                } else {
                    height[j] = tmp == 0 ? 0 : height[j]+1;
                }
            }
            result = max(result, maximalRectangle(height));
        }
        
        return result;
    }
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int maximalRectangle(vector<int> &height) {
        stack<int> s; // index of item in height
        int result = 0, len, cur;
        
        for (int i = 0; i < height.size();) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                cur = s.top();
                s.pop();
                if (s.empty()) len = i;
                else len = i - (s.top() + 1);
                
                result = max(result, height[cur] * len);
            }
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (s.empty()) len = height.size();
            else len = height.size() - (s.top() + 1);
            
            result = max (result, height[cur] * len);
        }
        
        return result;
    }
};