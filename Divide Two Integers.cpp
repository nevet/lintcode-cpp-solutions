class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    void convert(int ix, long long &lx, long long &mul) {
        if (ix > 0) lx = ix; else {
            lx = -(long long)ix; mul *= -1ll;
        }
    }
    
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        
        long long ans = 0; long long mul = 1;
        long long ldividend, ldivisor;
        
        convert(dividend, ldividend, mul);
        convert(divisor, ldivisor, mul);
        
        long long i = 31ll;
        while (ldividend && i >= 0ll) {
            if (ldividend >= ldivisor << i) {
                ans += 1ll << i;
                ldividend -= ldivisor << i;
            }
            
            i --;
        }
        
        fprintf(stderr, "%lld|", ans);
        
        return ans * mul > 2147483647ll ? 2147483647 : ans * mul;
    }
};