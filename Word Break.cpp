typedef pair<string, int> si;

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    // TLE N^2
    bool wordBreak(string s, unordered_set<string> &dict) {
        // f[i] = max(f[i - j]) + 1
        if (s == "" && dict.empty()) return true;
        
        int maxLen = 0;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it ++) {
            maxLen = max(maxLen, (int)it->size());
        }
        
        int len = s.size();
        bool f[len + 5];
        memset(f, 0, sizeof(f));
        fprintf(stderr, "%d ", len);
        for (int i = 0; i < len; i ++) {
            for (int j = 1; j <= maxLen && j <= i + 1; j ++) {
                string cur = s.substr(i - j + 1, j);
                if (dict.find(cur) != dict.end()) {
                    f[i] = f[i] || (i - j >= 0 ? f[i - j] : true);
                }
                if (f[i]) break;
            }
        }
        
        return f[len - 1];
    }
};