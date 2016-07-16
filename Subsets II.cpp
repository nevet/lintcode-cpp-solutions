class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    map<int, int> mapper;
    vector<vector<int> > ans;
    
    void makeSet(const vector<int> &S, int mask, vector<int> v) {
        ans.push_back(v);
        if (mask == 0) return;
        
        unordered_set<int> hash;
        
        while (mask) {
            int pos = mask & -mask;
            int inx = mapper[pos];
            mask ^= pos;
            
            if (hash.find(S[inx]) != hash.end()) continue;
            hash.insert(S[inx]);
            v.push_back(S[inx]);
            makeSet(S, mask, v);
            v.pop_back();
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        for (int i = 0; i <= 30; i ++) mapper[1 << i] = i;
        vector<int> v;
        sort(S.begin(), S.end());
        makeSet(S, (1 << S.size()) - 1, v);
        
        return ans;
    }
};
