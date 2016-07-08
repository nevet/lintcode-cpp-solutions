class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int MAX = 214748364;
    int reverseInteger(int n) {
        int mul = n < 0 ? -1 : 1;
        n *= mul;
        
        int x = 0;
        while (n) {
            x += n % 10;
            n /= 10;
            if (x > MAX) return 0;
            if (n) x *= 10;
        }
        
        return x * mul;
    }
};