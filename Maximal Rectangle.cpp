class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    typedef pair<int, int> ii;
    int maximalRectangle(vector<vector<bool> > &matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        vector<vector<int> > mat(n);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (j) {
                    mat[i].push_back(mat[i][j - 1]);
                    if (matrix[i][j]) mat[i][j] ++; else mat[i][j] = 0;
                } else {
                    mat[i].push_back(matrix[i][j] ? 1 : 0);
                }
                // printf("%d ", mat[i][j]);
            }
            
            // printf("\n");
        }
        
        stack<ii> stk;
        int ans = 0;
        
        for (int j = 0; j < m; j ++) {
            for (int i = 0; i < n; i ++) {
                ans = max(ans, mat[i][j]);
                
                int lowest = i;
                while (!stk.empty() && stk.top().first > mat[i][j]) {
                    lowest = stk.top().second;
                    ans = max(ans, stk.top().first * (i - lowest));
                    stk.pop();
                }
                
                stk.push(ii(mat[i][j], lowest));
            }
            
            while (!stk.empty()) {
                ans = max(ans, stk.top().first * (n - stk.top().second));
                stk.pop();
            }
        }
        
        return ans;
    }
};