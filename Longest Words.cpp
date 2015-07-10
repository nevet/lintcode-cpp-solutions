// 3 wa
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> v;
        int cur;
        int n = dictionary.size();
        int m = 0;
        
        if (dictionary.empty()) return v;
        
        for (int i = 0; i < n; i ++) {
            if (v.empty()) {
                v.push_back(dictionary[i]);
                cur = 0;
            } else {
                if (dictionary[i].length() > v[0].length()) {
                    v[0] = dictionary[i];
                    cur = 0;
                } else
                if (dictionary[i].length() == v[0].length()) {
                    if (cur < v.size() - 1) {
                        v[cur + 1] = dictionary[i];
                    } else {
                        v.push_back(dictionary[i]);
                    }
                    
                    cur ++;
                }
            }
        }
        
        while (v.size() > cur + 1) {
            v.pop_back();
        }
        
        return v;
    }
};
