class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        unordered_map<int, int> hash;
        vector<int> unique;
        
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (hash.find(nums[i]) == hash.end()) unique.push_back(nums[i]);
            hash[nums[i]] ++;
        }
        
        int m = unique.size();
        for (int i = 0; i < m; i ++) {
            if (hash[unique[i]] > n / k) return unique[i];
        }
    }
};
