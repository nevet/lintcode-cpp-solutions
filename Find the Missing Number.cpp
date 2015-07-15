// 2 wa
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] >= 0) {
                int next = nums[i];
                
                while (next >= 0 && next < n) {
                    int t = nums[next];
                    nums[next] = -1;
                    next = t;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] >= 0) return i;
        }
    }
};
