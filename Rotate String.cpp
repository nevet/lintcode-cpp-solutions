class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void reverse(string &s, int l, int r) {
        int i = l;
        int j = r;
        
        while (i < j) {
            s[i] ^= s[j] ^= s[i] ^= s[j];
            i ++; j --;
        }
    }
    
    void rotateString(string &str,int offset){
        int len = str.size();
        if (len == 0) return;
        
        offset %= len;
        if (offset == 0) return;
        
        int i = str.size() - offset;
        reverse(str, 0, i - 1);
        reverse(str, i, str.size() - 1);
        reverse(str, 0, str.size() - 1);
    }
};
