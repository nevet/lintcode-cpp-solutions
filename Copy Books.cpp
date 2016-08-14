class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // f[i][j] = min(max(f[k][j - 1], sum[k + 1][i]))
        int n = pages.size();
        if (n <= k) {
            int t = pages[0];
            for (int i = 1; i < n; i ++) t = max(t, pages[i]);
            return t;
        }
        
        int s[n], f[n][k];
        for (int i = 0; i < n; i ++)
            if (i) f[i][0] = s[i] = s[i - 1] + pages[i]; else f[i][0] = s[i] = pages[i];
            
        for (int j = 1; j < k; j ++) {
            for (int i = j; i < n; i ++) {
                f[i][j] = max(f[0][j - 1], s[i] - s[0]);
                for (int p = 1; p < i; p ++)
                    f[i][j] = min(f[i][j], max(f[p][j - 1], s[i] - s[p]));
            }
        }
        
        return f[n - 1][k - 1];
    }
};