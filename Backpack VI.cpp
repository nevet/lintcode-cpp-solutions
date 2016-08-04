class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        int f[target + 5];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int j = 1; j <= target; j ++) {
            f[j] = 0;
            for (int i = 0; i < nums.size(); i ++) {
                if (j - nums[i] >= 0) f[j] += f[j - nums[i]];
            }
        }
        
        return f[target];
    }
};