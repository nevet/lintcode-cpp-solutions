// ohko
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        int f[n];
        
        memset(f, sizeof(f), 0);
        
        if (n < 2) return 1;
        
        f[0] = 1;
        f[1] = 1;
        
        for (int i = 2; i <= n; i ++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        return f[n];
    }
};

