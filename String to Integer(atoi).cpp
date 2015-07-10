// 4 wa
class Solution {
public:
    string trim(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (s[i] == ' ') i ++;
        while (s[j] == ' ') j --;
        
        return s.substr(i, j - i + 1);
    }
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int mul = 1;
        
        str = trim(str);
        
        if (str[0] == '-') mul = -1;
        
        int len = str.length();
        
        long long ans = 0;
        
        for (int i = (str[0] == '-' || str[0] == '+'); i < len; i ++) {
            if (isdigit(str[i])) {
                ans *= 10;
                ans += str[i] - '0';
                
                if (mul == 1 && ans > 2147483647) {
                    return 2147483647;
                } else
                if (mul == -1 && ans > 2147483648) {
                    return -2147483648;
                }
            } else {
                if (str[i] != '.') return ans * mul;
                
                i ++;
                
                while (i < len && str[i] == '0') i ++;
                
                if (i < len) {
                    if (isdigit(str[i])) {
                        return 0;
                    }
                    
                    return ans * mul;
                }
            }
        }
        
        return ans * mul;
    }
};
