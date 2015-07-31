// ohko
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int n = A.size();
        
        if (n <= 2) return n;
        
        bool d = A[0] > A[1];
        int cnt = 2;
        int ans = 2;
        
        for (int i = 2; i < n; i ++) {
            if ((A[i - 1] > A[i] && d) || (A[i - 1] < A[i] && !d)) {
                cnt ++;
                ans = max(ans, cnt);
            } else {
                cnt = 2;
                d = !d;
            }
        }
        
        return ans;
    }
};
