class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();
        if (m == 0) return ans;
        
        int control[2] = {m, n - 1};
        int i, j, d, t;
        i = j = d = t = 0;
        while (control[0] >= 0 && control[1] >= 0) {
            for (int k = 0; k < control[t]; k ++) {
                ans.push_back(matrix[i][j]);
                if (k + 1 < control[t]) { i += di[d]; j += dj[d];}
            }
            
            control[t] --; t ^= 1;
            d = (d + 1) % 4;
            i += di[d]; j += dj[d];
        }
        
        return ans;
    }
};