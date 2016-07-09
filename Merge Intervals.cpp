/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}
    
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int i, j;
        i = j = 0;
        vector<Interval> ans;
        
        while (j < n) {
            while (j < n && intervals[j].end <= intervals[i].end) j ++;
            if (j < n) {
                if (intervals[j].start <= intervals[i].end) {
                    intervals[i].end = intervals[j].end;
                    j ++;
                } else {
                    ans.push_back(intervals[i]);
                    i = j; j ++;
                }
            }
        }
        
        ans.push_back(intervals[i]);
        
        return ans;
    }
};