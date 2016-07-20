typedef pair<int, int> ii;
typedef pair<ii, int> iii;
    
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    map<iii, int> memo;
    
    int dp(vector<int> &A, int n, int k, int t) {
        // printf("%d %d %d\n", n, k, t);
        if (k == 0 && t == 0) return 1;
        if (n == 1) {
            if (k == 1 && t == A[0]) return 1;
            return 0;
        }
        if (t < 0 || n < k) return 0;
        
        iii paired = iii(ii(n, k), t);
        if (memo.find(paired) != memo.end()) return memo[paired];
        memo[paired] = dp(A, n - 1, k, t) + dp(A, n - 1, k - 1, t - A[n - 1]);
        // printf("%d %d %d %d\n", n, k, t, memo[paired]);
        return memo[paired];
    }
    
    int kSum(vector<int> A, int k, int target) {
        int n = A.size();
        return dp(A, n - 1, k, target) + dp(A, n - 1, k - 1, target - A[n - 1]);
    }
};