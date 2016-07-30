class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        for (int i = 1; i < n; i ++) {
            if (i % 2 && nums[i - 1] > nums[i] || i % 2 == 0 && nums[i - 1] < nums[i]) {
                nums[i] ^= nums[i - 1] ^= nums[i] ^= nums[i - 1];
            }
        }
    }
};