// didn't solve, refer to other's solution
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        int m1, m2;
        int c1, c2;
        int n = nums.size();
        
        m1 = nums[0];
        c1 = 0;
        
        while (c1 < n && nums[c1] == m1) {
            c1 ++;
        }
        
        if (c1 == n) return m1;
        
        m2 = nums[c1];
        c2 =1;
        
        for (int i = c1 + 1; i < n; i ++) {
            if (nums[i] == m1) {
                c1 ++;
            } else
            if (nums[i] == m2) {
                c2 ++;
            } else 
            if (c1 == 0) {
                m1 = nums[i];
                c1 = 1;
            } else
            if (c2 == 0) {
                m2 = nums[i];
                c2 = 1;
            } else {
                c1 --;
                c2 --;
            }
        }
        
        c1 = 0;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] == m1) c1 ++;
        }
        
        if (c1 > n / 3) return m1;
        
        return m2;
    }
};

