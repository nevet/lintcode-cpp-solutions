class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        int ans = nums[0];
        int t = ans;
        for (int i = 1; i < n; i ++) {
            t = min(nums[i], t + nums[i]);
            ans = min(ans, t);
        }
        
        return ans;
    }
};
