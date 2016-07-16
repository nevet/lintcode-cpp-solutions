class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // compare with left bottom (LB):
        // target < LB, search matrix[i-1][j]
        // target == LB, ans ++, search matrix[i - 1][j + 1]
        // target > LB, search matrix[i][j + 1]
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        int i, j, ans;
        i = n - 1; j = ans = 0;
        
        while (i >= 0 && j < m) {
            if (matrix[i][j] == target) {
                ans ++;
                i --; j ++;
            } else if (matrix[i][j] > target) {
                i --;
            } else if (matrix[i][j] < target) {
                j ++;
            }
        }
        
        return ans;
    }
};
