/*
 *  Max Points on a Line
 *      Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) return points.size();
        int result = 0;
        unordered_map<double, int> slope_count;
        
        int same = 0;       // number of points at the same position
        int count = 0;      // number of points in the same line with some slope
        int max_count = 1;  // maximum of count
        for (int i = 0; i < points.size(); i++) {
            slope_count.clear();
            
            same = 0;
            max_count = 1;
            for (int j = i+1; j < points.size(); j++) {
                double slope;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                    continue;
                }
                
                if (points[i].x == points[j].x) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                }
                
                count = 0;
                if (slope_count.find(slope) != slope_count.end()) {
                    count = ++slope_count[slope];
                } else {
                    count = 2;
                    slope_count[slope] = 2;
                }
                if (max_count < count) max_count = count;
            }
            if (max_count + same > result) result = max_count + same;
        }
        
        return result;
    }
};