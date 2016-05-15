class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > ans;
    bool visited[1000 + 5];
    
    void work(vector<int> nums, int x, vector<int> &v) {
        if (x == nums.size() && x) {
            ans.push_back(v);
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (visited[i]) continue;
            
            v.push_back(nums[i]);
            visited[i] = true;
            work(nums, x + 1, v);
            v.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int> > permute(vector<int> nums) {
        vector<int> v;
        memset(visited, 0, sizeof(visited));
        work(nums, 0, v);
        return ans;
    }
};
