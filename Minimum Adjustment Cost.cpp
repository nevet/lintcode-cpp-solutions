class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int abs(int a) {
        return a < 0 ? -a : a;
    }
    
    int MinAdjustmentCost(vector<int> A, int target) {
        // f[i][j] = min(f[i - 1][j - target] + abs(A[i] - j))
        int f[A.size() + 5][105];
        memset(f, 0, sizeof(f));
        
        for (int i = 1; i <= 100; i ++) f[0][i] = abs(i - A[0]);
        
        for (int i = 1; i < A.size(); i ++) {
            for (int j = 100; j >= 1; j --) {
                f[i][j] = f[i - 1][min(100, j + target)];
                for (int k = min(100, j + target) - 1; k >= j - target && k >= 1; k --) {
                    f[i][j] = min(f[i][j], f[i - 1][k]);
                }
                f[i][j] += abs(j - A[i]);
            }
        }
        
        int ans = f[A.size() - 1][1];
        for (int i = 2; i <= 100; i ++) ans = min(ans, f[A.size() - 1][i]);
        
        return ans;
    }
};