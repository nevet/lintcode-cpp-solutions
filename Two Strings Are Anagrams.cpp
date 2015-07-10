// 2 wa
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        int h[128];
        int lenS = s.length();
        int lenT = t.length();
        
        memset(h, 0, sizeof(h));
        
        for (int i = 0; i < lenS; i ++) {
            h[s[i]] ++;
        }
        
        for (int j = 0; j < lenT; j ++) {
            if (!h[t[j]]) return false;
            
            h[t[j]] --;
        }
        
        for (int i = 0; i < 128; i ++) {
            if (h[i]) return false;
        }
        
        return true;
    }
};
