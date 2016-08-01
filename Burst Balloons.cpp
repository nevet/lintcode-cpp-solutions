class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // f[i][j] = max(f[i][k - 1] + f[k + 1][j] + a[i - 1] * a[k] * a[j + 1])
        // very importantly, the cost is a[i - 1] and a[j + 1], not a[k - 1] and a[k + 1]!!!
        // it is because after bursting i to j with last shot at k, i - 1 and
        // j + 1 would be adjcent, so for the last shot we should choose a[i - 1]
        // and a[j + 1] as cost.
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int f[n + 5][n + 5], a[n + 2];
        memset(f, 0, sizeof(f));
        a[0] = a[n + 1] = 1;
        for (int i = 0; i < n; i ++) a[i + 1] = nums[i];
        
        for (int l = 1; l <= n; l ++) {
            for (int i = 1; i <= n - l + 1; i ++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k ++) f[i][j] = max(f[i][j], a[i - 1] * a[j + 1] * a[k] + f[i][k - 1] + f[k + 1][j]);
            }
        }
        
        // for (int i = 0; i < n; i ++) {
        //     for (int j = 0; j < n; j ++) printf("%d ", f[i][j]);
        //     printf("\n");
        // }
        
        return f[1][n];
    }
};
