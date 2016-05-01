class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        if (word1 == "") return word2.size();
        if (word2 == "") return word1.size();
        int n = word1.size();
        int m = word2.size();
        
        string a = '#' + word1;
        string b = '#' + word2;
        
        int f[n + 5][m + 5];
        memset(f, 0, sizeof(f));
        
        for (int i = 1; i <= m; i ++) f[0][i] = i;
        for (int i = 1; i <= n; i ++) f[i][0] = i;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                f[i][j] = f[i - 1][j - 1];
                if (a[i] != b[j]) {
                    f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1])) + 1;
                }
            }
        }
        
        return f[n][m];
    }
};
