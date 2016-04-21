class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // f[i][0] = max(f[i - 1][0], f[i - 1][1])
        // f[i][1] = f[i - 1][0] + a[i]
        int n = A.size();
        long long rob, notRob;
        
        if (n == 0) return 0;
        
        rob = A[0];
        notRob = 0;
        
        for (int i = 1; i < n; i ++) {
            long long prevNotRob = notRob;
            notRob = max(notRob, rob);
            rob = prevNotRob + A[i];
        }
        
        return max(notRob, rob);
    }

    // solution 2
    long long houseRobberSolution2(vector<int> A) {
        // f[i][0] = max(f[i - 1][0], f[i - 1][1])
        // f[i][1] = f[i - 1][0] + a[i] = max(f[i - 2][0], f[i - 2][1])
        
        // g[i] = max(f[i][0], f[i][1])
        // f[i][0] = g[i - 1]
        // f[i][1] = g[i - 2] + a[i]
        // g[i] = max(g[i - 1], g[i - 2] + a[i])
        int n = A.size();
        long long a, b;
        
        if (n == 0) return 0;
        if (n < 3) return max(A[0], A[n - 1]);
        
        a = A[0];
        b = max(A[0], A[1]);
        
        for (int i = 2; i < n; i ++) {
            long long c = b;
            b = max(b, a + A[i]);
            a = c;
        }
        
        return max(a, b);
    }
};
