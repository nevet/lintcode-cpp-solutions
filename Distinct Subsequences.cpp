class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinctN2Memory(string &s, string &t) {
        // f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * (t[i] == s[j]) 
        int n = s.size();
        int m = t.size();
        
        if (m > n) return 0;
        if (n == 0) return 0;
        if (m == 0) return 1;
        
        int f[m + 5][n + 5];
        memset(f, 0, sizeof(f));
        
        for (int i = 0; i < n; i ++) f[0][i] = (i ? f[0][i - 1] : 0) + (t[0] == s[i]);
        for (int i = 1; i < m; i ++)
            for (int j = i; j < n; j ++)
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * (t[i] == s[j]);
            
        return f[m - 1][n - 1];
    }
    
    int numDistinct(string &s, string &t) {
        // f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * (t[i] == s[j]) 
        int n = s.size();
        int m = t.size();
        
        if (m > n) return 0;
        if (n == 0) return 0;
        if (m == 0) return 1;
        
        int f[n + 5];
        memset(f, 0, sizeof(f));
        
        for (int i = 0; i < n; i ++) f[i] = (i ? f[i - 1] : 0) + (t[0] == s[i]);
        for (int i = 1; i < m; i ++) {
            int old = f[i - 1];
            for (int j = i; j < n; j ++) {
                int newValue = (j == i ? 0 : f[j - 1]) + old * (t[i] == s[j]);
                old = f[j];
                f[j] = newValue;
            }
        }
            
        return f[n - 1];
    }
};
