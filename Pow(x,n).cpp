class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        double ans = 1;
        double curP = x;
        
        bool isNeg = n < 0;
        if (isNeg) n = -n;
        
        while (n) {
            if (n & 1) {
                ans *= curP;
            }
            
            curP *= curP;
            n >>= 1;
        }
        
        return isNeg ? 1 / ans : ans;
    }
};