/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> newIntervals;
        
        if (intervals.size() == 0) {
            newIntervals.push_back(newInterval);
            return newIntervals;
        }
        
        int pos = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp) - intervals.begin();
        
        for (int i = 0; i < pos; i ++) newIntervals.push_back(intervals[i]);
        if (pos == 0 || intervals[pos - 1].end < newInterval.start) {
            while (pos < intervals.size() && intervals[pos].start <= newInterval.end) pos++;
            newInterval.end = max(newInterval.end, intervals[pos - 1].end);
            newIntervals.push_back(newInterval);
        } else {
            newIntervals[pos - 1].end = max(newIntervals[pos - 1].end, newInterval.end);
            int curRight = newIntervals[pos - 1].end;
            int oriPos = pos;
            while (pos < intervals.size() && intervals[pos].start <= curRight) pos++;
            newIntervals[oriPos - 1].end = max(newIntervals[oriPos - 1].end, intervals[pos - 1].end);
        }
        
        while (pos < intervals.size()) {
            newIntervals.push_back(intervals[pos]);
            pos ++;
        }
        
        return newIntervals;
    }
};