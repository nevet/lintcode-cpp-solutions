// ohko
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        
        int len = 2147483647;
        
        if (strs[0] == "") return "";
        
        for (int i = 0; i < strs.size(); i ++) len = min(len, (int)strs[i].length());
        
        for (int i = 0; i < len; i ++) {
            char x = strs[0][i];
            
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[j][i] != x) {
                    if (i == 0) return "";
                    
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
