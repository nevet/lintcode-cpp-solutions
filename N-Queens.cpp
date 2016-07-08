class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > ans;
    int hash[1 << 17];
    int mask, high;
    
    void print(vector<int> v) {
        vector<string> sol;
        
        for (int i = 0; i < v.size(); i ++) {
            string cur = "";
            for (int j = 0; j < v.size(); j ++) {
                if (v[i] != j) cur += "."; else cur += "Q";
            }
            sol.push_back(cur);
        }
        
        ans.push_back(sol);
    }
    
    void solve(int q, vector<int> v, int col, int ld, int rd) {
        if (q == 0) {
            print(v);
            return;
        }
        
        int poss = col & ld & rd;
        // printf("%d %d %d %d\n", col, ld, rd, poss);
        while (poss) {
            int p = poss & -poss;
            v.push_back(hash[p]);
            // printf("%d %d %d %d\n", rd, p, mask, (((rd ^ p) << 1) & mask) | 1);
            solve(q - 1, v, col ^ p, ((ld ^ p) >> 1) | high, (((rd ^ p) << 1) & mask) | 1);
            v.pop_back();
            poss ^= p;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<int> v;
        
        // if (n < 4) return ans;
        
        int col, ld, rd;
        mask = col = ld = rd = (1 << n) - 1;
        high = 1 << (n - 1);
        for (int i = 0; i < 17; i ++) hash[1 << i] = i;
        
        solve(n, v, col, ld, rd);
        
        return ans;
    }
};
