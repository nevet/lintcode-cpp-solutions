class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        int hash[240];
        memset(hash, 127, sizeof(hash));
        int MAX = hash[0];
        int len = target.size();
        for (int i = 0; i < len; i ++) {
            if (hash[target[i]] == MAX) hash[target[i]] = 1; else hash[target[i]] ++;
        }
        int slen = source.size();
        int p1, p2;
        for (p1 = p2 = 0; p2 < slen; p2 ++) {
            if (hash[source[p2]] != MAX) hash[source[p2]]--; else continue;
            while (p1 < len && hash[target[p1]] <= 0) p1 ++;
            if (p1 == len) break;
        }
        
        fprintf(stderr, "%d %d|", p1, p2);
        
        if (p1 < len) return "";
        
        int bp1, bp2, ans;
        ans = p2;
        bp1 = p1 = 0; bp2 = p2;
        
        while (p2 < slen) {
            while (p1 < p2) {
                if (hash[source[p1]] != MAX) {
                    hash[source[p1]]++;
                    if (hash[source[p1]] > 0) break;
                }
                
                p1 ++;
            }
            
            if (p2 - p1 < ans) {
                ans = p2 - p1;
                bp1 = p1; bp2 = p2;
            }
            
            if (ans == 0) break;
            
            p2 ++;
            while (p2 < slen) {
                if (hash[source[p2]] != MAX) {
                    hash[source[p2]] --;
                    if (source[p2] == source[p1]) break;
                }
                p2 ++;
            }
            p1 ++;
        }
        
        fprintf(stderr, "%d %d|", bp1, bp2);
        
        return source.substr(bp1, bp2 - bp1 + 1);
    }
};
