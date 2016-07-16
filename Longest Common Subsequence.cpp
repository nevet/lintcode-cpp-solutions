class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // if A[i] == B[j], f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1)
        // f[i][j] = max(f[i - 1][j], f[i][j - 1])
        // f[0][i] = A[0] == B[i], f[i][0] = A[i] == B[0]
        int f[A.size() + 5][B.size() + 5];
        memset(f, 0, sizeof(f));
        
        if (A.size() == 0 || B.size() == 0) return 0;
        
        for (int i = 0; i < A.size(); i ++) {
            if (A[i] == B[0]) f[i][0] = 1;
        }
        
        for (int i = 0; i < B.size(); i ++) {
            if (B[i] == A[0]) f[0][i] = 1;
        }
        
        for (int i = 1; i < A.size(); i ++)
            for (int j = 1; j < B.size(); j ++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (A[i] == B[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
            
        return f[A.size() - 1][B.size() - 1];
    }
};
