class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        double sum, ssqra, ssqrb;
        
        sum = ssqra = ssqrb = 0;
        int n = A.size();
        
        for (int i = 0; i < n; i ++) {
            sum += A[i] * B[i];
            ssqra += A[i] * A[i];
            ssqrb += B[i] * B[i];
        }
        
        if (ssqra == 0 || ssqrb == 0) return 2;
        
        double d = sqrt(ssqra) * sqrt(ssqrb);
        
        return sum / d;
    }
};
