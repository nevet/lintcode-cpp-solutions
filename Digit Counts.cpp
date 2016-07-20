class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int f[10];
    
    int count(int k, int cur, int rem, int mul, int x) {
        int ans = 0;
        if (cur == 1) {
            if (x >= k) return 1;
            return 0;
        }
        
        ans += f[cur - 1] * x;
        if (x == k) {
            ans += rem + 1;
        } else if (x > k && k != 0) {
            ans += mul;
        }
        
        return ans;
    }
    
    int digitCounts(int k, int n) {
        int cur = 1;
        f[0] = 0;
        for (int i = 1; i < 9; i ++) {
            f[i] = i * cur;
            cur *= 10;
        }
        
        if (n == k && k == 0) return 1;
        
        int ans, rem, mul;
        ans = rem = 0;
        mul = cur = 1;
        while (n) {
            ans += count(k, cur, rem, mul, n % 10);
            rem += (n % 10) * mul;
            n /= 10; cur ++; mul *= 10;
        }
        
        return ans;
    }
};