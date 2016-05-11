class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        bool f[m + 5];
        memset(f, 0, sizeof(f));
        int n = A.size();
        
        int ans = 0;
        f[0] = true;
        for (int i = 0; i < n; i ++) {
            for (int j = m; j >= A[i]; j --) {
                f[j] = f[j - A[i]] || f[j];
                if (f[j]) ans = max(ans, j);
            }
        }
        
        return ans;
    }
};