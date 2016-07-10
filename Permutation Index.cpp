class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        long long perm[A.size() + 1] ;
        perm[0] = 1;
        for (long long i = 1; i <= A.size(); i ++) {
            perm[i] = perm[i - 1] * i;
        }
        
        long long ans = 0;
        for (int i = 0; i < A.size(); i ++) {
            long long s = 0;
            for (int j = i + 1; j < A.size(); j ++) {
                if (A[j] < A[i]) s ++;
            }
            ans += s * perm[A.size() - 1 - i];
        }
        
        return ans + 1;
    }
};