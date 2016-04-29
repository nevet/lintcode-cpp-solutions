class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& a) {
        int curMax, curMin;
        int n = a.size();
        int best = -214748364;
        int i = 0;
        while (i < n) {
            while (i < n && a[i] == 0) {
                best = max(best, 0);
                i ++;
            }
            
            curMax = curMin = a[i];
            best = max(a[i], best);
            i ++;
            while (i < n && a[i] != 0) {
                int oldMax = curMax;
                curMax = max(a[i], max(a[i] * curMax, a[i] * curMin));
                curMin = min(a[i], min(a[i] * curMin, a[i] * oldMax));
                best = max(best, curMax);
                // printf("%d %d %d\n", a[i], curMax, curMin);
                i ++;
            }
        }
        
        return best;
    }
};