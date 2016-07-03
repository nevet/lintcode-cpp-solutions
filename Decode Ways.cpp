class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // f[i] = f[i - 1] + f[i - 2], f[i - 2] only if s[i-1, i] is smaller than 26
        if (s == "0") return 0;
        if (s.size() <= 1) return s.size();
        
        int a = 1; // f[i - 2]
        int b = 1; // f[i - 1]
        int ans = 0;
        int n = s.size();
        
        for (int i = 1; i < n ; i ++) {
            if (s[i] != '0') {
                ans = b;
                if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                    ans += a;
                }
            } else if (s[i] == '0' && s[i - 1] > '0' && s[i - 1] <= '2') ans = a; else {
                return 0;
            }
            
            a = b;
            b = ans;
        }
        
        return ans;
    }
};