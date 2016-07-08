class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        int f[n + 5][m + 5];
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (i == 0) f[i][j] = j ? f[i][j - 1] + grid[i][j] : grid[i][j]; else
                if (j == 0) f[i][j] = i ? f[i - 1][j] + grid[i][j] : grid[i][j]; else
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
            
        return f[n - 1][m - 1];
    }
};
