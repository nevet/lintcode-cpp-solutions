// 2 wa
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> h;
        vector<string> v;
        
        h.clear();
        
        for (int i = 0; i < strs.size(); i ++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            
            if (h.count(t) == 0) {
                h[t] = i;
            } else {
                if (h[t] >= 0) {
                    v.push_back(strs[h[t]]);
                    h[t] = -1;
                }
                
                v.push_back(strs[i]);
            }
        }
        
        return v;
    }
};

