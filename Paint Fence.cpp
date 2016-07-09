class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // f[i][j]= f[i - 1][k != j] + f[i - 2][k != j]
        // if i - 2 == 0 second term gives 1 directly
        // f[1][0..k - 1] = 1
        if (n == 0) return 0;
        if (k == 1 && n > 2) return 0;
        
        int g[n + 5], f[n + 5][k + 5];
        memset(g, 0, sizeof(g)); memset(f, 0, sizeof(f));
        for (int i = 0; i <= 1; i ++)
            for (int j = 0; j < k; j ++) f[i][j] = 1;
        g[0] = 2; g[1] = k;
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j < k; j ++) {
                f[i][j] = g[i - 1] - f[i - 1][j] + g[i - 2] - f[i - 2][j];
                g[i] += f[i][j];
            }
        }
        
        return g[n];
    }
};