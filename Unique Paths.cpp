// ohko
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        int f[m][n];
        
        memset(f, 0, sizeof(f));
        
        for (int i = 0; i < m; i ++) f[i][0] = 1;
        for (int i = 0; i < n; i ++) f[0][i] = 1;
        
        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j ++)
                f[i][j] = f[i - 1][j] + f[i][j - 1];
                
        return f[m - 1][n - 1];
    }
};

