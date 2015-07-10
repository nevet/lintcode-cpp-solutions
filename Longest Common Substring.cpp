// ohko
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int f[1000][1000];
     
    int longestCommonSubstring(string &A, string &B) {
        int lena = A.length();
        int lenb = B.length();
        
        memset(f, 0, sizeof(f));
        
        int ans = 0;
        
        for (int i = 1; i <= lena; i ++) {
            for (int j = 1; j <= lenb; j ++) {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    
                    ans = max(ans, f[i][j]);
                }
            }
        }
        
        return ans;
    }
};

