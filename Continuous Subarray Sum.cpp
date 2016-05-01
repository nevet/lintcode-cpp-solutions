class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int cur, ans, b[2], c[2];
        int n = A.size();
        
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        
        if (n) cur = ans = A[0];
        
        for (int i = 1; i < n; i ++) {
            if (A[i] > cur + A[i]) {
                cur = A[i];
                c[0] = c[1] = i;
            } else {
                cur += A[i];
                c[1] = i;
            }
            
            if (cur > ans) {
                ans = cur;
                b[0] = c[0];
                b[1] = c[1];
            }
        }
        
        
        return vector<int>(b, b + 2);
    }
};