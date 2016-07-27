class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int abs(int x) {
        return x < 0 ? -x : x;
    }
    
    int maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int f[n + 5][2], g[n + 5][2];
        int frontMax, frontMin, backMax, backMin;
        frontMax = frontMin = f[0][0] = f[0][1] = nums[0];
        backMax = backMin = g[n - 1][0] = g[n - 1][1] = nums[n - 1];
        for (int i = 1; i < n; i ++) {
            frontMax = max(nums[i] + frontMax, nums[i]);
            f[i][0] = max(f[i - 1][0], frontMax);
            frontMin = min(nums[i] + frontMin, nums[i]);
            f[i][1] = min(f[i - 1][1], frontMin);
            
            backMax = max(nums[n - i - 1] + backMax, nums[n - i - 1]);
            g[n - i - 1][0] = max(g[n - i][0], backMax);
            backMin = min(nums[n - i - 1] + backMin, nums[n - i - 1]);
            g[n - i - 1][1] = min(g[n - i][1], backMin);
        }
        
        int ans = 0;
        for (int i = 1; i < n; i ++) {
            ans = max(ans, max(abs(f[i - 1][1] - g[i][0]), abs(f[i - 1][0] - g[i][1])));
        }
        
        return ans;
    }
};
