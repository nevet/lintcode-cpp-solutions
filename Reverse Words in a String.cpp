class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverse(string s) {
        string rev = s;
        int i, j;
        i = 0; j = rev.size() - 1;
        while (i < j) {
            rev[i] ^= rev[j] ^= rev[i] ^= rev[j];
            i ++; j --;
        }
        
        // printf("%s\n", rev.c_str());
        return rev;
    }
    
    string reverseWords(string s) {
        int len = s.size();
        if (len == 0) return s;
        
        int i = 0;
        string ans = "";
        while (i < len) {
            while (i < len && s[i] == ' ') i ++;
            if (i < len) {
                int j = i;
                while (j < len && s[j] != ' ') j ++;
                ans += reverse(s.substr(i, j - i)) + " ";
                i = j;
            }
        }
        
        return ans.size() >= 1 ? reverse(ans).substr(1, ans.size() - 1) : ans;
    }
};