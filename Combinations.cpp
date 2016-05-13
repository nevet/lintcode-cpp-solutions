class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > ans;
    void work(int n, int k, int d, vector<int> &v) {
        if (k == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i = d; i <= n; i ++) {
            v.push_back(i);
            work(n, k - 1, i + 1, v);
            v.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<int> v;
        work(n, k, 1, v);
        return ans;
    }
};