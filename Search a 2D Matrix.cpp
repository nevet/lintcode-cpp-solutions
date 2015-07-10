// 1 wa
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<int> col;
        
        if (matrix.empty()) return false;
        
        if (matrix[0][0] > target) return false;
        
        for (int i = 0; i < matrix.size(); i ++) {
            col.push_back(matrix[i][0]);
        }
        
        int t = lower_bound(col.begin(), col.end(), target) - col.begin();
        
        if (col[t] > target) {
            t --;
        }
        int p = lower_bound(matrix[t].begin(), matrix[t].end(), target) - matrix[t].begin();
        
        if (matrix[t][p] == target) return true;
        
        return false;
    }
};

