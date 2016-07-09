class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    int ans;
    int hash[1 << 17];
    int mask, high;

    void solve(int q, int col, int ld, int rd) {
        if (q == 0) {
            ans ++;
            return;
        }

        int poss = col & ld & rd;
        while (poss) {
            int p = poss & -poss;
            solve(q - 1, col ^ p, ((ld ^ p) >> 1) | high, (((rd ^ p) << 1) & mask) | 1);
            poss ^= p;
        }
    }

    int totalNQueens(int n) {
        // if (n < 4) return ans;

        int col, ld, rd;
        mask = col = ld = rd = (1 << n) - 1;
        high = 1 << (n - 1);
        for (int i = 0; i < 17; i ++) hash[1 << i] = i;

        ans = 0;
        solve(n, col, ld, rd);

        return ans;
    }
};