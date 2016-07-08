class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + a[i][j]
        int n = triangle.size();
        if (n == 0) return 0;
        
        int f[triangle.size() + 5];
        memset(f, 255, sizeof(f));
        
        f[0] = triangle[0][0];
        for (int i = 1; i < n; i ++) {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j >= 0; j --) {
                if (j) f[j] = min(f[j], f[j - 1]) + triangle[i][j]; else f[j] += triangle[i][j];
            }
        }
        
        int ans = f[0];
        for (int i = 1; i < n; i ++) ans = min(ans, f[i]);
        return ans;
    }
};
