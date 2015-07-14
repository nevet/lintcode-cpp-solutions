// 9 wa
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // find the highest index such that s[i] < s[i + 1]
        int i, j;
        int n = nums.size();
        vector<int> next;
        
        if (n == 1) return nums;
        
        for (i = n - 2; i >= 0; i --) {
            if (nums[i] < nums[i + 1]) break;
        }
        
        if (i == -1) {
            for (i = n - 1; i >= 0; i --) next.push_back(nums[i]);
            
            return next;
        }
        
        // find the highest index j > i and s[j] > s[i]
        for (j = n - 1; j > i; j --) {
            if (nums[j] > nums[i]) break;
        }
        
        // swap s[i] and s[j]
        if (i != j && j < n) {
            nums[i] ^=nums[j] ^= nums[i] ^= nums[j];
        }
        
        // reverse all order after i
        for (j = 0; j <= i; j ++) next.push_back(nums[j]);
        for (j = n - 1; j > i; j --) next.push_back(nums[j]);
        
        return next;
    }
};
