class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // f[i][k] = min(f[i - 1][!k]) + costs[i][k]
        // f[0][k] = costs[0][k]
        int n = costs.size();
        if (n == 0) return 0;
        
        int f[n][3];
        for (int i = 0; i < 3; i ++) f[0][i] = costs[0][i];
        
        for (int i = 1; i < n ;i ++) {
            f[i][0] = min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
            f[i][1] = min(f[i - 1][0], f[i - 1][2]) + costs[i][1];
            f[i][2] = min(f[i - 1][0], f[i - 1][1]) + costs[i][2];
        }
        
        return min(min(f[n - 1][0], f[n - 1][1]), f[n - 1][2]);
    }
};