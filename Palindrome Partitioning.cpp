class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> ans;
    vector<string> tans;
    
    bool ok(string s) {
        int i, j;
        i = 0; j = s.length() - 1;
        
        while (i <= j && s[i] == s[j]) {
            i ++; j --;
        }
        
        return i > j;
    }
    
    void p(string s) {
        if (s == "") {
            ans.push_back(tans);
            return;
        }
        
        int len = s.length();
        for (int i = 1; i <= len; i ++) {
            string sub = s.substr(0, i);
            // printf("sub = %s\n", sub.c_str());
            if (ok(sub)) {
                tans.push_back(sub);
                p(s.substr(i, len - i));
                tans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        p(s);
        return ans;
    }
};