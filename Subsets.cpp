class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > ans;
    
    void work(vector<int> &nums, int d, vector<int> &temp) {
        int n = nums.size();
        if (d >= n) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = d; i <= n; i ++) {
            if (i < n) temp.push_back(nums[i]);
            work(nums, i + 1, temp);
            if (i < n) temp.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<int> v;
    	work(nums, 0, v);
    	return ans;
    }
};