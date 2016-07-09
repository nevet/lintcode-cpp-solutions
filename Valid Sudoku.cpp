class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool verifyRow(const vector<vector<char>>& board) {
        if (board.size() != 9) return false;
        for (int i = 0; i < 9; i ++) {
            int mask = (1 << 9) - 1;
            if (board[i].size() != 9) return false;
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;
                int p = 1 << (board[i][j] - '0' - 1);
                if (p & mask) mask ^= p; else return false;
            }
        }
        
        return true;
    }
    
    bool verifyCol(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) {
            int mask = (1 << 9) - 1;
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] == '.') continue;
                int p = 1 << (board[j][i] - '0' - 1);
                if (p & mask) mask ^= p; else return false;
            }
        }
        
        return true;
    }
    
    bool verifyCell(const vector<vector<char>>& board) {
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                int mask = (1 << 9) - 1;
                for (int k = 0; k < 9; k ++) {
                    int ni = i * 3 + k / 3;
                    int nj = j * 3 + k % 3;
                    if (board[ni][nj] == '.') continue;
                    int p = 1 << (board[ni][nj] - '0' - 1);
                    if (p & mask) mask ^= p; else return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(const vector<vector<char>>& board) {
        return verifyRow(board) && verifyCol(board) && verifyCell(board);
    }
};