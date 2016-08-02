typedef pair<int, int> ii;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    // O(n log n)
    int maxArea(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<ii> v;
        for (int i = 0; i < n; i ++) v.push_back(ii(heights[i], i));
        sort(v.begin(), v.end());
        int mx[n + 5], mn[n + 5];
        mx[n - 1] = mn[n - 1] = v[n - 1].second;
        for (int i = n - 2; i >= 0; i --) {
            mx[i] = max(mx[i + 1], v[i].second);
            mn[i] = min(mn[i + 1], v[i].second);
        }
        
        int area = 0;
        for (int i = 0; i < n; i ++) {
            area = max(area, v[i].first * (mx[i] - mn[i]));
            while (i + 1 < n && v[i].first == v[i + 1].first) i ++;
        }
        
        return area;
    }
};