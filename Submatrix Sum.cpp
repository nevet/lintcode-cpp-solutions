class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int> > construct(int i, int j, int k, int p) {
        vector<vector<int> > ans {{p, k}, {i, j}};
        return ans;
    }

    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // any submatrix M(i,j,p,k) = M(i,j,0,0) - M(i,k-1,0,0) - M(p-1,j,0,0) + M(p-1,k-1,0,0)
        // let M(i,j,p,k) = 0 we have M(i,j,0,0) - M(i,k-1,0,0) - M(p-1,j,0,0) + M(p-1,k-1,0,0) = 0
        // which is M(i,j,0,0) - M(i,k-1,0,0) = M(p-1,j,0,0) - M(p-1,k-1,0,0), where p < i
        // notice we have the same form for the both side.
        // therefore we could remember all values of M(i,j,0,0) - M(i,k-1,0,0) in a hash map, and
        // when calculating a new value, we check the map to see if we have the same value before.
        int n = matrix.size();
        if (n == 0) return construct(0, 0, 0, 0);
        int m = matrix[0].size();
        if (m == 0) return construct(0, 0, 0, 0);

        int sum[n + 5][m + 5];
        unordered_map<int, int> hash[m + 5][m + 5];

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                sum[i][j] = matrix[i][j];
                if (j) sum[i][j] += sum[i][j - 1];
                if (i) sum[i][j] += sum[i - 1][j];
                if (i && j) sum[i][j] -= sum[i - 1][j - 1];

                for (int k = 0; k <= j; k ++) {
                    int s = sum[i][j] - (k != 0) * sum[i][k - 1];
                    if (s == 0 || hash[j][k].find(s) != hash[j][k].end()) {
                        return construct(i, j, k, hash[j][k][s]);
                    }
                    hash[j][k][s] = i + 1;
                }
            }
        }

        return construct(0, 0, 0, 0);
    }
};
