class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    
    vector<vector<int>> generateMatrix(int n) {
        int curi, curj, curd;
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i ++) {
            vector<int> v(n, 0);
            ans.push_back(v);
        }
        
        int cur = 1;
        curi = curj = curd = 0;
        while (cur <= n * n) {
            ans[curi][curj] = cur++;
            if (curi + di[curd] >= n || curi + di[curd] < 0 || curj + dj[curd] >= n || curj + dj[curd] < 0 || ans[curi + di[curd]][curj + dj[curd]]) {
                curd = (curd + 1) % 4;
            }
            
            curi += di[curd];
            curj += dj[curd];
        }
        
        return ans;
    }
};