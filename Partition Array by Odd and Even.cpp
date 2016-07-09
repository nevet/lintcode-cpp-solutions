class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int i = 0;
        int j = nums.size();
        if (j <= 1) return;
        
        while (i < j) {
            while (i < j && (nums[i] & 1)) i ++;
            while (i < j && (nums[j] & 1) == 0) j --;
            if (i < j) {
                nums[i] ^= nums[j] ^= nums[i] ^= nums[j];
                i ++; j --;
            }
        }
    }
};