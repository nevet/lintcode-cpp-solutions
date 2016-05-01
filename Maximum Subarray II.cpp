class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> a) {
        int n = a.size();
        
        if (n == 0) return 0;
        if (n == 1) return a[0];
        
        int f[n + 5], grandf[n + 5], g[n + 5], grandg[n + 5];
        
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(grandf, 0, sizeof(grandf));
        memset(grandg, 0, sizeof(grandg));
        
        for (int i = 0; i < n; i ++) {
            f[i] = i ? max(f[i - 1] + a[i], a[i]) : a[i];
            grandf[i] = i ? max(grandf[i - 1], f[i]) : f[i];
            g[n - i - 1] = i ? max(g[n - i] + a[n - i - 1], a[n - i - 1]) : a[n - i - 1];
            grandg[n - i - 1] = i ? max(grandg[n - i], g[n - i - 1]) : g[n - i - 1];
        }
        
        int ans = grandf[0] + grandg[1];
        for (int i = 1; i < n - 1; i ++) {
            ans = max(ans, grandf[i] + grandg[i + 1]);
        }
        
        return ans;
    }
};
