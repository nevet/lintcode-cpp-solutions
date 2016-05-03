class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > ans;
    
    void find(vector<int> &candidates, int target, int cur, int ind, vector<int> temp) {
        if (cur > target) return;
        
        if (cur == target) {
            ans.push_back(temp);
            return;
        }
        
        int n = candidates.size();
        for (int i = ind; i < n; i ++) {
            temp.push_back(candidates[i]);
            find(candidates, target, cur + candidates[i], i, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        find(candidates, target, 0, 0, temp);
        
        return ans;
    }
};