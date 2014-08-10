/*
 *  Insert Interval
 *      Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 *      You may assume that the intervals were initially sorted according to their start times.
 *
 *      Example 1:
 *      Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 *      Example 2:
 *      Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 *      This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int new_s, new_e;
        //bool inserted = false;
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval.end < it->start) {
                // newInterval is ahead of intervals[i]
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end) {
                // newInterval is behind of intervals[i]
                it++;
                continue;
            } else {
                // overlap
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
private:
    int min(int a, int b) {
        return a <= b ? a : b;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
    bool overlap(Interval &a, Interval &b) {
        if (a.start > b.end) return false;
        if (a.end < b.start) return false;
        return true;
    }
};