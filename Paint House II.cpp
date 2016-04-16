class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // f[i][k] = min(f[i - 1][j != k]) + costs[i][k] = g[i - 1][k] + costs[i][k]
        // f[0][k] = costs[0][k]
        // g[i][k] = min(f[i][j != k])
        
        int n = costs.size();
        if (n == 0) return 0;
        
        int m = costs[0].size();
        if (m == 0) return 0;
        
        int f[n + 5][m + 5];
        int g[n + 5][m + 5];
        
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        
        for (int i = 0; i < n; i ++) {
            int m1, m2, m1p;
            
            for (int k = 0; k < m; k ++) {
                if (i) f[i][k] = g[i - 1][k];
                f[i][k] +=  costs[i][k];
                
                if (k == 0) {
                    m1 = f[i][k];
                    m1p = k;
                    m2 = 214748300;
                } else if (f[i][k] < m1) {
                    m2 = m1;
                    m1 = f[i][k];
                    m1p = k;
                } else if (f[i][k] < m2) {
                    m2 = f[i][k];
                }
            }
            
            for (int k = 0; k < m; k ++) {
                if (k != m1p) g[i][k] = m1; else g[i][k] = m2;
            }
        }
        
        int ans = f[n - 1][0];
        for (int i = 1; i < m; i ++) {
            ans = min(ans, f[n - 1][i]);
        }
        
        return ans;
    }
};