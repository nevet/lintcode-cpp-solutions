// 1 wa
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int ans = -1;
    
    int peak(vector<int> A, int l, int r) {
        if (l == r) return -1;
        
        if (l == r - 1) {
            if (A[l] < A[r]) return -1;
            
            return -2;
        }
        
        int m = (l + r) >> 1;
        int lp = peak(A, l, m);
        int rp = peak(A, m + 1, r);
        
        if (lp >= 0) return lp;
        if (rp >= 0) return rp;
        
        if (lp == -1 && rp == -1) {
            if (A[m] <= A[m + 1]) return -1;
            if (A[m] > A[m + 1]) return m;
        } else
        if (lp == -1 && rp == -2) {
            if (A[m] > A[m + 1]) return m;
            if (A[m] < A[m + 1]) return m + 1;
        } else
        if (lp == -2) {
            return -2;
        }
    }
    
    int findPeak(vector<int> A) {
        int n = A.size();
        
        return peak(A, 0, n - 1);
    }
};

