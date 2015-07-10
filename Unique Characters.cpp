// ohko
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        if (str.length() == 1) return true;
        
        sort(str.begin(), str.end());
        
        int len = str.length();
        
        for (int i = 1; i < len; i ++) {
            if (str[i] == str[i - 1]) return false;
        }
        
        return true;
    }
};
