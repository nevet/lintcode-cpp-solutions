// ohko
class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    
    int n, m;
    
    bool ok(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void flood(int i, int j, vector<vector<bool>>& grid) {
        if (grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        
        for (int d = 0; d < 4; d ++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            
            if (ok(ni, nj)) {
                flood(ni, nj, grid);
            }
        }
    }
    
    int numIslands(vector<vector<bool>>& grid) {
        int ans = 0;
        
        if (grid.empty()) return 0;
        
        n = grid.size();
        m = grid[0].size();
        
        if (m == 0) return 0;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    flood(i, j, grid);
                    ans ++;
                }
            }
        }
        
        return ans;
    }
};
