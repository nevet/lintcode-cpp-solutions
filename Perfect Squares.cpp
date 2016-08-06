class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int MAX = 2147483647;
    
    map<int, int> memo;
    
    int find(int d, int cur, int left) {
        if (left == 0) return cur;
        if (d == 0) return -1;
        if (memo.find(left) != memo.end()) return memo[left] + cur;
        int ans = MAX;
        for (int i = 1; i * i <= left; i ++) {
            int t = find(d - 1, cur + 1, left - i * i);
            if (t != -1) ans = min(ans, t);
        }
        if (ans == MAX) return -1;
        return memo[left] = ans;
    }
    
    int numSquaresRecursive(int n) {
        memo[0] = 0;
        
        for (int d = 1; ; d ++) {
            int ans = find(d, 0, n);
            if (ans != -1) return ans;
        }
        
        return -1;
    }
    
    int numSquares(int n) {
        int f[n + 5];
        f[0] = 0;
        for (int i = 1; i <= n; i ++) {
            f[i] = MAX;
            for (int j = 1; j * j <= i; j ++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }
        
        return f[n];
    }
};