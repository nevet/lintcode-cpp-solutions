class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int n = A.size();
        vector<int> v(2, 0);
        if (n < 2) return v;
        if (n == 2) A;
        
        int x = A[0];
        for (int i = 1; i < n; i ++) x ^= A[i];
        x = x & -x;
        for (int i = 0 ; i < n; i ++) {
            if (A[i] & x) v[0] ^= A[i]; else v[1] ^= A[i];
        }
        return v;
    }
};