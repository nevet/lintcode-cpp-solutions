class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    map<char, int> mapper = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int romanToInt(string& s) {
        int n = s.size();
        if (n == 0) return 0;
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += mapper[s[i]];
            if (i + 1 < n && mapper[s[i]] < mapper[s[i + 1]])  ans -= 2 * mapper[s[i]];
        }
        
        return ans;
    }
};