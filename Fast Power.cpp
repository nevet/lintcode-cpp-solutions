// 3 wa
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        long long ans = 1;
        long long m = a;
        
        while (n) {
            if (n & 1) {
                ans = (ans * m) % b;
            }
            
            n >>= 1;
            m = m * m % b;
        }
        
        return ans % b;
    }
};
