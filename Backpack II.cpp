class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        int n = A.size();
        if (n == 0) return 0;
        
        int f[m + 5], ans;
        memset(f, 255, sizeof(f));
        
        ans = f[0] = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = m; j >= A[i]; j --) {
                if (f[j - A[i]] != -1) f[j] = max(f[j - A[i]] + V[i], f[j]);
            }
        }
        
        for (int i = 0; i <= m; i ++) ans = max(ans, f[i]);
        
        return ans;
    }
};