// 2 wa
class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i, j, k;
        int ans = 2147483647;
        int ans2;
        
        for (int i = 0; i < n - 2; i ++) {
            j = i + 1;
            k = n - 1;
            
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                
                if (abs(t - target) < ans) {
                    ans = abs(t - target);
                    ans2 = t;
                }
                
                if (t < target) j ++; else
                if (t > target) k --; else {
                    return target;
                }
            }
        }
        
        return ans2;
    }
};