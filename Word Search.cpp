class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    vector<vector<bool> > visited;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    
    bool find(vector<vector<char> > &board, int i, int j, int cur, string word) {
        if (cur == word.size()) return true;
        // fprintf(stderr, "%d %d %c ", i, j, board[i][j]);
        
        visited[i][j] = true;
        bool found = false;
        
        for (int d = 0; d < 4; d ++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < board.size() &&
                nj >= 0 && nj < board[0].size()) {
                    // fprintf(stderr, "%d %d %c %c ", ni, nj, board[ni][nj], word[cur]);
                    // fprintf(stderr, visited[ni][nj] ? "true|" : "false|");
                    if (!visited[ni][nj] && board[ni][nj] == word[cur]) {
                        found = found || find(board, ni, nj, cur + 1, word);
                    }
            }
        }
        
        return found;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        int n = board.size();
        if (n == 0) return word == "";
        int m = board[0].size();
        if (m == 0) return word == "";
        if (word == "") return false;
        
        for (int i = 0; i < n; i ++) visited.push_back(vector<bool>(m, false));
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == word[0]) {
                    for (int p = 0; p < n; p ++)
                        for (int q = 0; q < m; q ++) visited[p][q] = false;
                    visited[i][j] = true;
                    if (find(board, i, j, 1, word)) return true;
                }
            }
            
        return false;
    }
};