// ohko
class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string say(string s) {
        int i, j, len = s.length();
        string str = "";
        
        i = j = 0;
        
        while (i < len) {
            int c = 0;
            j = i;
            
            while (s[i] == s[j]) {
                c ++;
                j ++;
            }
            
            str.push_back(c + 48);
            str.push_back(s[i]);
            
            i = j;
        }
        
        return str;
    }
    
    string countAndSay(int n) {
        string f[n];
        
        f[0] = "1";
        
        for (int i = 1; i < n; i ++) {
            f[i] = say(f[i - 1]);
        }
        
        return f[n - 1];
    }
};
