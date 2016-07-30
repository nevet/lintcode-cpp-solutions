class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash;
        int n = num.size();
        if (n <= 1) return n;
        
        for (int i = 0; i < n; i ++) hash.insert(num[i]);
        
        int ans = 0;
        while (!hash.empty()) {
            int t = 1;
            int s = *hash.begin(); hash.erase(s);
            for (int x = s - 1; !hash.empty() && hash.find(x) != hash.end(); x --) {
                hash.erase(x); t ++;
            }
            for (int x = s + 1; !hash.empty() && hash.find(x) != hash.end(); x ++) {
                hash.erase(x); t ++;
            }
            
            ans = max(ans, t);
        }
        
        return ans;
    }
};