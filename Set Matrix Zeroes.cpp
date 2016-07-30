class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;
        
        bool cc, cr;
        cc = cr = false;
        for (int i = 0; i < n; i ++)
            cr = cr || !matrix[i][0];
        for (int j = 0; j < m; j ++)
            cc = cc || !matrix[0][j];
        
        for (int i = 1; i < n; i ++)
            for (int j = 1; j < m; j ++)
                if (!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;
        
        for (int i = 1; i < n; i ++)
            if (!matrix[i][0]) 
                for (int j = 1; j < m; j ++) matrix[i][j] = 0;
            
        for (int j = 1; j < m; j ++)
            if (!matrix[0][j])
                for (int i = 1; i < n; i ++) matrix[i][j] = 0;
        
        if (cr)
            for (int i = 0; i < n; i ++) matrix[i][0] = 0;
        
        if (cc)
            for (int j = 0; j < m; j ++) matrix[0][j] = 0;
    }
};