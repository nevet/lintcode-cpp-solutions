// ohko
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x == 0) return 0;
        
        if (x > 2147395600) return 46340;
        
        int l = 1;
        int r = 46340;
        
        while (l < r) {
            int m = ((l + r) >> 1) + 1;
            int p = m * m;
            
            if (p < x) l = m; else
            if (p > x) r = m - 1; else return m;
        }
        
        return l;
    }
};
