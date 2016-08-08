class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        
        unordered_set<char> hash;
        
        int i, j, t, ans;
        i = j = t = ans = 0;
        
        while (j < n) {
            while (j < n && hash.find(s[j] - 'a') == hash.end()) {
                hash.insert(s[j++] - 'a');
                t ++;
                ans = max(ans, t);
            }
            
            while (i < j && j < n && hash.find(s[j] - 'a') != hash.end()) {
                hash.erase(s[i++] - 'a');
                t --;
            }
        }
        
        return ans;
    }
};