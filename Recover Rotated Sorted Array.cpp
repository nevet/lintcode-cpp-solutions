class Solution {
public:
    void reverse(vector<int> &v, int l, int r) {
        while (l < r) {
            v[l] ^= v[r] ^= v[l] ^= v[r];
            l ++; r --;
        }
    }
    
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] < nums[i - 1]) {
                reverse(nums, 0, i - 1);
                reverse(nums, i, nums.size() - 1);
                reverse(nums, 0, nums.size() - 1);
                return;
            }
        }
    }
};