/*
 *  Merge Intervals
 *      Given a collection of intervals, merge all overlapping intervals.
 *
 *      For example,
 *      Given [1,3],[2,6],[8,10],[15,18],
 *      return [1,6],[8,10],[15,18].
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) return result;
        result.insert(result.begin(), intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            insert(result, intervals[i]);
        }
        
        return result;
    }
private:
    void insert(vector<Interval> &intervals, Interval &newI) {
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (newI.end < it->start) {
                intervals.insert(it, newI);
                return;
            } else if (newI.start > it->end) {
                it++;
                //continue;
            } else {
                newI.start = min(newI.start, it->start);
                newI.end = max(newI.end, it->end);
                it = intervals.erase(it);
            }
        }
        
        intervals.insert(intervals.end(), newI);
        return;
    }
    
    int max(int a, int b) { return a > b ? a : b;}
    int min(int a, int b) { return a < b ? a : b;}
};