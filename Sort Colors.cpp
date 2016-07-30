class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i, j;
        i = -1; j = n;
        for (int k = 0; k < j; k ++) {
            if (nums[k] == 0) {
                i ++;
                if (i != k) nums[i] ^= nums[k] ^= nums[i] ^= nums[k];
            } else if (nums[k] == 2) {
                j --;
                if (j != k) nums[j] ^= nums[k] ^= nums[j] ^= nums[k];
                k --;
            }
        }
    }
};