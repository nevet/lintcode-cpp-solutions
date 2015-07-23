// 7 wa
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        
        if (n == 0) return 0;
        
        int m = obstacleGrid[0].size();
        
        int f[n + 5][m + 5];
        
        memset(f, 0, sizeof(f));
        
        f[0][0] = 1 - obstacleGrid[0][0];
        
        for (int i = 1; i < n; i ++) {
            f[i][0] = f[i - 1][0];
            if (obstacleGrid[i][0]) {
                f[i][0] = 0;
            }
        }
        
        for (int i = 1; i < m; i ++) {
            f[0][i] = f[0][i - 1];
            if (obstacleGrid[0][i]) {
                f[0][i] = 0;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (obstacleGrid[i][j]) f[i][j] = 0; else {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        
        return f[n - 1][m - 1];
    }
};
