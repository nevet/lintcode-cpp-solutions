class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        int curi, curj, di, dj;
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        if (n == 1) return matrix[0];
        int m = matrix[0].size();
        
        fprintf(stderr, "%d %d, ", n, m);
        
        curi = curj = 0;
        di = -1; dj = 1;
        
        while (!(curi == n - 1 && curj == m - 1)) {
            ans.push_back(matrix[curi][curj]);
            fprintf(stderr, "%d %d, ", curi, curj);
            if (curi + di < 0 || curi + di >= n) {
                if (curj + 1 >= m) curi ++; else curj ++;
                di *= -1; dj *= -1;
            } else if (curj + dj < 0 || curj + dj >= m) {
                if (curi + 1 >= n) curj ++; else curi ++;
                di *= -1; dj *= -1;
            } else {
                curi += di; curj += dj;
            }
        }
        
        ans.push_back(matrix[n - 1][m - 1]);
        
        return ans;
    }
};