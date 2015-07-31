// 1 wa
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int n = nums.size();
        long long ans = -2147483648;
        long long cur = -2147483648;
        
        for (int i = 0; i < n; i ++) {
            cur = max(cur + (long long)nums[i], (long long)nums[i]);
            ans = max(ans, cur);
        }
        
        return (int)ans;
    }
};

