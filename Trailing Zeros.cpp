// ohko
class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long t = 5;
        long long ans = 0;
        
        while (t < n) {
            ans += n / t;
            t *= 5;
        }
        
        return ans;
    }
};
