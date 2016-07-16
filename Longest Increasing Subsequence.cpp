class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> v;
        int n = nums.size();
        if (n <= 1) return n;
        
        v.push_back(nums[0]);
        if (nums[1] < nums[0]) v[0] = nums[1]; else v.push_back(nums[1]);
        
        for (int i = 2; i < n; i ++) {
            int firstGreater = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();
            if (firstGreater == v.size()) v.push_back(nums[i]); else {
                v[firstGreater] = nums[i];
            }
        }
        
        return v.size();
    }
};
