class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        
        int i, j;
        i = j = 0;
        while (j < n) {
            while (i < n && nums[i] != 0) i ++;
            if (j < i) j = i;
            while (j < n && nums[j] == 0) j ++;
            int p = j;
            while (i < p && nums[i] == 0 && j < n && nums[j] != 0) {
                nums[i] = nums[j]; nums[j] = 0;
                i ++; j ++;
            }
        }
    }
};