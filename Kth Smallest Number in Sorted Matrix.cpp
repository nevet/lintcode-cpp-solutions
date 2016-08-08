typedef pair<int, int> ii;
typedef pair<int, ii> iii;
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        if (k == 1) return matrix[0][0];
        if (k == n * m) return matrix[n - 1][m - 1];
        
        priority_queue<iii> pq;
        bool f[n + 5][m + 5];
        memset(f, 0, sizeof(f));
        
        pq.push(iii(-matrix[0][0], ii(0, 0)));
        f[0][0] = true;
        
        for (int i = 1; i < k; i ++) {
            iii u = pq.top(); pq.pop();
            int ni = u.second.first; int nj = u.second.second;
            if (ni + 1 < n && !f[ni + 1][nj]) {
                f[ni + 1][nj] = true;
                pq.push(iii(-matrix[ni + 1][nj], ii(ni + 1, nj)));
            }
            if (nj + 1 < m && !f[ni][nj + 1]) {
                f[ni][nj + 1] = true;
                pq.push(iii(-matrix[ni][nj + 1], ii(ni, nj + 1)));
            }
        }
        
        return -pq.top().first;
    }
};