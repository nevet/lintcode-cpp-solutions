// 3 wa
class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        string t;
        int len = s.length();
        
        for (int i = 0; i < len; i ++) {
            if (isalnum(s[i])) t.push_back(tolower(s[i]));
        }
        
        string p = t;
        reverse(t.begin(), t.end());
        return p == t;
    }
};
