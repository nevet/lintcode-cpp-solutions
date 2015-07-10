// 3 wa
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int i, j;
        int n = nums.size();
        
        i = 0; j = n - 1;
        
        while (i < j) {
            while (i < n && nums[i] < k) i ++;
            while (j >= 0 && nums[j] >= k) j --;
            
            if (i < j) {
                nums[i] ^= nums[j] ^= nums[i] ^= nums[j];
            
                i ++; j --;
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] >= k) return i;
        }
        
        return n;
    }
};
