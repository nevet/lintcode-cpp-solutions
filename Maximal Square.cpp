class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        // f[i][j] = min(f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]) + 1
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        int f[n + 5][m + 5];
        
        memset(f, sizeof(f), 0);
        
        int ans = 0;
        for (int i = 0; i < m; i ++) { f[0][i] = matrix[0][i]; ans = max(ans, f[0][i]); }
        for (int i = 0; i < n; i ++) { f[i][0] = matrix[i][0]; ans = max(ans, f[i][0]); }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                f[i][j] = matrix[i][j];
                if (matrix[i][j]) {
                    f[i][j] = min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1])) + 1;
                }
                
                ans = max(ans, f[i][j]);
            }
        }
        
        return ans * ans;
    }
};