class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        vector<int> ans(n);
        int i = n - 2;
        
        while (i >= 0 && nums[i] <= nums[i + 1]) i --;
        if (i < 0) {
            for (int i = n - 1; i >= 0; i --) ans[n - 1 - i] = nums[i];
        } else {
            for (int j = 0; j < i; j ++) ans[j] = nums[j];
            int j = n - 1;
            while (nums[j] >= nums[i]) { ans[i + n - j] = nums[j]; j --; }
            ans[i + n - j] = nums[i]; ans[i] = nums[j]; j --;
            while (j > i) { ans[i + n - j] = nums[j]; j --; }
        }
        
        return ans;
    }
};