class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> ans;
    
    void rec(int l, int r) {
        // error case
        if (l > r) return;
        
        // fprintf(stderr, "l = %d r = %d|", l, r);
        if (r - l == 1) {
            rec(l, l);
            rec(r, r);
            return;
        }
        
        if (l == r) {
            ans.push_back(l);
            return;
        }
        
        int m = (l + r) >> 1;
        rec(l, m);
        rec(m + 1, r);
    }
    
    vector<int> numbersByRecursion(int n) {
        int r = 1;
        while (n--) {
            r *= 10;
        }
        rec(1, r - 1);
        
        return ans;
    }
};