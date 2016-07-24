/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
typedef pair<int, int> ii;
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<ii> v;
        int n = airplanes.size();
        if (n == 0) return 0;
        
        for (int i = 0; i < n; i ++) {
            v.push_back(ii(airplanes[i].start, 1));
            v.push_back(ii(airplanes[i].end, -1));
        }
        
        sort(v.begin(), v.end());
        
        int temp = 0;
        int ans = 0;
        for (int i = 0; i < 2 * n; i ++) {
            temp += v[i].second;
            ans = max(ans, temp);
        }
        
        return ans;
    }
};