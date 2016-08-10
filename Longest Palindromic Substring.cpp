class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        int len = s.size();
        char sc[2 * (len + 1) + 1];
        memset(sc, 0, sizeof(0));
        sc[0] = '$';
        for (int i = 0; i < len; i ++) {
            sc[i * 2 + 1] = '#';
            sc[(i + 1) * 2] = s[i];
        }
        sc[2 * len + 1] = '#'; sc[2 * (len + 1)] = '\0';
        
        int p[2 * (len + 1)], mx, id, ans, ansp;
        memset(p, sizeof(p), 0); mx = id = ans = ansp = 0;
        for (int i = 1; sc[i] != '\0'; i ++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (sc[i + p[i]] == sc[i - p[i]]) p[i] ++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            
            if (p[i] > ans) {
                ans = p[i];
                ansp = i;
            }
        }
        
        // printf("%s\n", sc);
        
        string sol = "";
        int i = ansp, j = ansp;
        while (ans) {
            if (sc[i] == '#') { i --; j ++; ans --; continue; }
            if (i == j) sol += sc[i]; else {
                sol = sc[i] + sol;
                sol = sol + sc[j];
            }
            i --; j ++; ans --;
        }
        
        return sol;
    }
};