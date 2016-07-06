class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    void print(int f[], int n) {
        for (int i = 0; i < n; i ++) {
            printf("%4d ", f[i]);
        }
        printf("\n");
    }
    
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        // f[i][k] = max(f[j][k - 1] + g[j + 1, i])
        int n = nums.size();
        if (n == 0) return 0;
        
        int f[n + 5], g[n + 5][n + 5], temp;
        
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        
        temp = f[0] = nums[0];
        for (int i = 1; i < n; i ++) {
            temp = max(temp + nums[i], nums[i]);
            f[i] = max(f[i - 1], temp);
        }
        
        for (int i = 0; i < n; i ++) {
            int temp = nums[i];
            g[i][i] = nums[i];
            for (int j = i + 1; j < n; j ++) {
                temp = max(temp + nums[j], nums[j]);
                g[i][j] = max(g[i][j - 1], temp);
            }
        }
        
        // for (int i = 0; i < n; i ++) {
        //     for (int j = 0; j < n; j ++) {
        //         printf("%4d ", g[i][j]);
        //     }
        //     printf("\n");
        // }
        
        // print(f, n);
        
        for (int i = 1; i < k; i ++) {
            for (int j = n - 1; j >= i; j --) {
                f[j] = -2147483648;
                for (int p = i - 1; p < j; p ++) {
                    f[j] = max(f[j], f[p] + g[p + 1][j]);
                }
            }
            
            // print(f, n);
        }
        
        return f[n - 1];
    }
};
