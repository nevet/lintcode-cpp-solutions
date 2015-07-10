// 2 wa
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > ans;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i, j, k, p;
        
        while (i < n - 2) {
            j = i + 1;
            k = n - 1;
            
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] < 0) j ++; else
                if (nums[j] + nums[k] + nums[i] > 0) k --; else {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    
                    ans.push_back(temp);
                    
                    p = j;
                    while (p < k && nums[p] == nums[j]) p ++;
                    j = p;
                    
                    p = k;
                    while (p > j && nums[p] == nums[k]) p --;
                    k = p;
                }
            }
            
            p = i;
            while (nums[p] == nums[i]) p ++;
            i = p;
        }
        
        return ans;
    }
};

