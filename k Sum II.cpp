class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > ans;
    
    void work(vector<int> &A, int left, int k, int t, vector<int> sol) {
        // printf("%d %d %d\n", left, k, t);
        if (left < k || k < 0 || t < 0) return;
        if (k == 0 && t == 0) {
            ans.push_back(sol);
            return;
        }
        
        for (int i = left - 1; i >= 0; i --) {
            sol.push_back(A[i]);
            work(A, i, k - 1, t - A[i], sol);
            sol.pop_back();
        }
    }
    
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        vector<int> sol;
        work(A, A.size(), k, target, sol);
        return ans;
    }
};
