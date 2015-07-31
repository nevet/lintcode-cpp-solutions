// 1 wa
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int c = 0;
        
        for (int i = s.length() - 1; i >= 0; i --) {
            if (s[i] == ' ') {
                break;
            }
            
            c ++;
        }
        
        return c;
    }
};
