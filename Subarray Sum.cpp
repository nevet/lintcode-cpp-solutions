// 1 wa
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> ans;
        
        int n = nums.size();
        
        vector<int> sums(n);
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                ans.push_back(i);
                ans.push_back(i);
                
                return ans;
            }
            
            if (i) sums[i] = sums[i - 1] + nums[i]; else sums[i] = nums[i];
            
            if (sums[i] == 0) {
                ans.push_back(0);
                ans.push_back(i);
                
                return ans;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (sums[j] - sums[i - 1] == 0) {
                    ans.push_back(i);
                    ans.push_back(j);
                    
                    return ans;
                }
            }
        }
        
        return ans;
    }
};

// 1 wa
class Solution2 {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> ans;
        unordered_map<int, int> hash;
        
        int n = nums.size();
        
        int sum = 0;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                ans.push_back(i);
                ans.push_back(i);
                
                return ans;
            }
            
            sum += nums[i];
            
            if (sum == 0) {
                ans.push_back(0);
                ans.push_back(i);
                
                return ans;
            }
            
            if (hash.count(sum) == 0) {
                hash[sum] = i;
            } else {
                ans.push_back(hash[sum] + 1);
                ans.push_back(i);
                
                return ans;
            }
        }
        
        return ans;
    }
};