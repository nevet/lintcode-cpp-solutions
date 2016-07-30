class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    
    void circulate(vector<vector<int> > &matrix, int i, int j, int n) {
        int x[4] = {i, i + n - 1, i + n - 1, i};
        int y[4] = {j, j, j + n - 1, j + n - 1};
        
        for (int k = 0; k < n - 1; k ++) {
            for (int p = 0; p < 3; p ++) {
                matrix[x[p]][y[p]] ^= matrix[x[p + 1]][y[p + 1]] ^= matrix[x[p]][y[p]] ^= matrix[x[p + 1]][y[p + 1]];
                x[p] += dx[p];
                y[p] += dy[p];
            }
            x[3] += dx[3]; y[3] += dy[3];
        }
    }
    
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        
        int i, j;
        i = j = 0;
        while (n > 1) {
            circulate(matrix, i, j, n);
            i ++; j ++; n -= 2;
        }
    }
};