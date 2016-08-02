class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    long long MAX = 2147483647ll;
    
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int n = A.size();
        int m = B.size();
        
        int i, j; i = j = 0;
        long long ans = MAX;
        while (i < n && j < m && ans > 0) {
            while (j < m && A[i] > B[j]) {
                ans = min(ans, (long long)A[i] - (long long)B[j]);
                j ++;
            }
            
            while (i < n && A[i] < B[j]) {
                ans = min(ans, (long long)B[j] - (long long)A[i]);
                i ++;
            }
            
            if (A[i] == B[j]) return 0;
        }
        
        return ans;
    }
};
