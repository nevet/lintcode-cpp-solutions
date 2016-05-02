class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    
    int n, m;
    
    bool vis[1000 + 5][1000 + 5];
    
    bool enclose(int i, int j, char rep, vector<vector<char>>& board) {
        // printf("now %d %d: ", i, j);
        if (i >= n || i < 0 || j >= m || j < 0) { return false; }
        if (board[i][j] == 'X') { return true; }
        
        board[i][j] = rep;
        vis[i][j] = true;
        // printf("replace %d\n", rep);
        bool en = true;
        for (int d = 0; d < 4; d ++) {
            if (!vis[i + di[d]][j + dj[d]]) {
                // printf("ni = %d, nj = %d\n", i + di[d], j + dj[d]);
                en = enclose(i + di[d], j + dj[d], rep, board) && en;
            }
        }
        
        return en;
    }
    
    void surroundedRegions(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        
        memset(vis, 0, sizeof(vis));
        
        int cur = 0;
        set<int> s;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                // printf(vis[i][j] ? "vis[%d][%d] = true\n":"vis[%d][%d] = false\n", i, j);
                if (board[i][j] != 'X' && !vis[i][j]) {
                    if (enclose(i, j, cur, board)) s.insert(cur);
                    cur ++;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                // printf("%d ", board[i][j]);
                if (board[i][j] == 'X') continue;
                if (s.find(board[i][j]) != s.end()) {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
            // printf("\n");
        }
    }
};