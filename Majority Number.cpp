// ohko
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int n = nums.size();
        int m = nums[0];
        int c = 1;
        
        for (int i = 1; i < n; i ++) {
            if (c == 0) {
                m = nums[i];
            }
            
            if (nums[i] == m) c ++; else c --;
        }
        
        if (c != 0) return m;
    }
};

