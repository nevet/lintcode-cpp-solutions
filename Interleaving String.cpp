class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // f[i][j] =
        // f[i - 1][j] if a[i] == s[i + j],
        // f[i][j - 1] if b[j] == s[i + j],
        // else false
        int n = s1.size();
        int m = s2.size();
        if (s3.size() != n + m) return false;
        
        bool f[n + 5][m + 5];
        f[0][0] = true;
        for (int i = 0; i < n; i ++) f[i + 1][0] = f[i][0] && (s1[i] == s3[i]);
        for (int i = 0; i < m; i ++) f[0][i + 1] = f[0][i] && (s2[i] == s3[i]);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                f[i + 1][j + 1] = false;
                f[i + 1][j + 1] = f[i + 1][j + 1] || (s1[i] == s3[i + j + 1] && f[i][j + 1]);
                f[i + 1][j + 1] = f[i + 1][j + 1] || (s2[j] == s3[i + j + 1] && f[i + 1][j]);
            }
            
        // for (int i = 0; i <= n; i ++) {
        //     for (int j = 0; j <= m; j ++) printf("%d ", f[i][j]); printf("\n");
        // }
        
        return f[n][m];
    }
};