class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    map<int, int> p;
    vector<vector<int> > ans;
    
    void permute(vector<int> &nums, int mask, vector<int> &v) {
        if (mask == 0) {
            ans.push_back(v);
            return;
        }
        
        unordered_set<int> hash;
        int curMask = mask;
        while (mask) {
            int pos = mask & -mask;
            int inx = p[pos];
            mask ^= pos;
            if (hash.find(nums[inx]) != hash.end()) continue;
            v.push_back(nums[inx]);
            hash.insert(nums[inx]);
            permute(nums, curMask ^ pos, v);
            v.pop_back();
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        for (int i = 0; i <= 30; i ++) p[1 << i] = i;
        int n = nums.size();
        vector<int> v;
        permute(nums, (1 << n) - 1, v);
        
        return ans;
    }
};