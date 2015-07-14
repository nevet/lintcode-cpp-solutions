// ohko
# define MAXINT 2147483647

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        int f[100];
        
        memset(f, sizeof(f), 0);
        
        f[0] = 0;
        f[1] = 1;
        
        for (int i = 2; i < 100; i ++) {
            if (MAXINT - f[i - 2] > f[i - 1]) {
                f[i] = f[i - 1] + f[i - 2];
            } else break;
        }
        
        return f[n - 1];
    }
};

