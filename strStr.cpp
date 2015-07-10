// 4 wa
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(char * s, char * t) {
        if (!s || !t) return -1;
        
        
        int lent = strlen(t);
        int lens = strlen(s);
        
        string source(s);
        string target(t);
        
        if (lent == 0 && lens == 0) return 0;
        
        for (int i = 0; i < lens; i ++) {
            int j = 0;
            int p = i;
            
            while (j < lent && p < lens && target[j] == source[p]) {
                j ++;
                p ++;
            }
            
            if (j == lent) return i;
        }
        
        return -1;
    }
};

