class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber(vector<int>::iterator begin, vector<int>::iterator end) {
        // f[i][0] = max(f[i - 1][0], f[i - 1][1])
        // f[i][1] = f[i - 1][0] + a[i] = max(f[i - 2][0], f[i - 2][1])
        
        // g[i] = max(f[i][0], f[i][1])
        // f[i][0] = g[i - 1]
        // f[i][1] = g[i - 2] + a[i]
        // g[i] = max(g[i - 1], g[i - 2] + a[i])
        int n = end - begin + 1;
        int a, b;
        
        if (n == 0) return 0;
        if (n < 3) {
            int a = *begin; begin ++;
            return max(a, *begin);
        }
        
        a = *begin; begin ++;
        b = max(a, *begin); begin ++;
        while (begin != end) {
            long long c = b;
            b = max(b, a + *begin);
            a = c;
            begin ++;
        }
        
        return max(a, b);
    }
    
    int houseRobber2(vector<int>& nums) {
        if (nums.size() <= 3) {
            int ans = 0;
            for (int i = 0; i < nums.size(); i ++) ans = max(ans, nums[i]);
            return ans;
        }
        
        auto second = nums.begin(); second ++;
        int without = houseRobber(second, nums.end());
        second++; auto second_last = nums.end(); second_last --;
        int with = houseRobber(second, second_last) + nums[0];
        return max(with, without);
    }
};